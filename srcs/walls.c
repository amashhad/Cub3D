/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 03:38:56 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 21:16:10 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <inttypes.h>

void	final_projection(t_data *data, t_walls *walls, int col)
{
	side_step(data, walls);
	wall_height(data, walls);
	if (!data->texture[walls->texture_id].addr)
		return;
	/* --- 4) map hit position to texture coordinate X --- */
	walls->texture_x = (int)(walls->wall_x * data->texture[walls->texture_id].width);
	if (walls->texture_x < 0)
		walls->texture_x = 0;
	if (walls->texture_x >= data->texture[walls->texture_id].width)
		walls->texture_x = data->texture[walls->texture_id].width - 1;
	if ((walls->side == 0 && walls->ray_dx > 0) || (walls->side == 1 && walls->ray_dy < 0))
		walls->texture_x = data->texture[walls->texture_id].width - walls->texture_x - 1;
	/* --- 5) draw vertical textured stripe --- */
	walls->tex_h = data->texture[walls->texture_id].height;
	walls->tex_bpp_bytes = data->texture[walls->texture_id].bpp / 8;
	walls->virt_bpp_bytes = data->mid_bpp / 8;
	walls->y = walls->start;
	while (walls->y <= walls->end)
	{
		/* proportionally map screen y → texture y */
		walls->d = (walls->y - walls->start) * walls->tex_h;
		if (walls->line_height != 0)
			walls->texture_y = (walls->d/walls->line_height);
		else
			walls->texture_y = 0;
		if (walls->texture_y < 0)
			walls->texture_y = 0;
		if (walls->texture_y >= walls->tex_h)
			walls->texture_y = walls->tex_h - 1;
		/* read pixel from texture */
		walls->src_offset = walls->texture_y * data->texture[walls->texture_id].len + walls->texture_x * walls->tex_bpp_bytes;
		walls->color = *(int *)(data->texture[walls->texture_id].addr + walls->src_offset);
		/* write pixel to virtual buffer */
		walls->dst_offset = walls->y * data->mid_len + col * walls->virt_bpp_bytes;
		*(int *)(data->mid_add + walls->dst_offset) = walls->color;
		walls->y++;
	}
}

void	setup_vars(t_data *data, t_walls *walls, int col)
{
	if (walls->ray_dx == 0.0)
		walls->delta_x = 1e30;
	else
		walls->delta_x = fabs(1.0/walls->ray_dx);
	if (walls->ray_dy == 0.0)
		walls->delta_y = 1e30;
	else
		walls->delta_y = fabs(1.0/walls->ray_dy);
	if (walls->ray_dx < 0)
	{
		walls->step_x = -1;
		walls->side_dist_x = (walls->px - walls->map_x) * walls->delta_x;
	}
	else
	{
		walls->step_x = 1;
		walls->side_dist_x = (walls->map_x + 1 - walls->px) * walls->delta_x;
	}
	if (walls->ray_dy < 0)
	{
		walls->step_y = -1;
		walls->side_dist_y = (walls->py - walls->map_y) * walls->delta_y;
	}
	else
	{
		walls->step_y = 1;
		walls->side_dist_y = (walls->map_y + 1 - walls->py) * walls->delta_y;
	}
	final_projection(data, walls, col);
}

void	project_walls(t_algo *algo, t_walls *walls, t_data *data)
{
	int	col;

	col = 0;
	while (col < data->screen->width)
	{
		walls->px = data->player->player_x / (double)TILE_SIZE;
		walls->py = data->player->player_y / (double)TILE_SIZE;
		walls->angle = algo->angle;
		walls->fov = algo->fov;
		walls->dist = (data->screen->width / 2.0) / tan(walls->fov / 2.0);
		walls->ray_angle = walls->angle - walls->fov / 2.0 + (col + 0.5) * (walls->fov / data->screen->width);
		walls->ray_dx = cos(walls->ray_angle);
		walls->ray_dy = sin(walls->ray_angle);
		walls->map_x = (int)walls->px;
		walls->map_y = (int)walls->py;
		setup_vars(data, walls, col);
		col++;
	}
}
