/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_imgs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/26 01:38:08 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 21:08:36 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mount_middle(t_data *data)
{
	data->mid_w = 0;
	data->mid_h = 0;
	data->middle = mlx_new_image(data->mlx, data->screen->width, data->screen->height);
	data->mid_add = mlx_get_data_addr(data->middle, &data->mid_bpp, &data->mid_len, &data->mid_endean);
}

static	void	side(t_walls *walls)
{
	if (walls->side == 0)
		walls->prep_dist = walls->side_dist_x - walls->delta_x;
	else
		walls->prep_dist = walls->side_dist_y - walls->delta_y;
	if (walls->prep_dist < 2)
		walls->prep_dist = 2;
}
void	side_step(t_data *data, t_walls *walls)
{
	while (1)
	{
		if (walls->side_dist_x < walls->side_dist_y)
		{
			walls->side_dist_x += walls->delta_x;
			walls->map_x += walls->step_x;
			walls->side = 0;
		}
		else
		{
			walls->side_dist_y += walls->delta_y;
			walls->map_y += walls->step_y;
			walls->side = 1;
		}
		if (walls->map_x < 0 || walls->map_y < 0
			|| walls->map_y >= data->mdata->map_row
			|| walls->map_x >= data->mdata->map_coln
			|| data->mdata->arr_map[walls->map_y][walls->map_x] == '1')
			break;
	}
	side(walls);
}
