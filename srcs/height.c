/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:35:33 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 21:25:13 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/* --- 3) select correct texture (N, S, E, W) --- */
static void	further_calculation(t_walls *walls)
{
	if (walls->side == 0)
	{
		if (walls->step_x == -1)
			walls->texture_id = 3;
		else
			walls->texture_id = 2;
		walls->wall_x = walls->py + walls->prep_dist * walls->ray_dy;
	}
	else
	{
		if (walls->step_y == -1)
			walls->texture_id = 0;
		else
			walls->texture_id = 1;
		walls->wall_x = walls->px + walls->prep_dist * walls->ray_dx;
	}
	walls->wall_x -= floor(walls->wall_x);
}

/* --- 2) project wall height --- */
void	wall_height(t_data *data, t_walls *walls)
{
	walls->line_height = (int)(walls->dist / walls->prep_dist);
	if (walls->line_height <= 0)
		walls->line_height = 1;
	if (walls->line_height > data->screen->height)
		walls->line_height = data->screen->height;
	walls->start = (-walls->line_height / 2) + data->screen->height / 2;
	walls->end = (walls->line_height / 2) + data->screen->height / 2;
	if (walls->start < 0)
		walls->start = 0;
	if (walls->end >= data->screen->height)
		walls->end = data->screen->height - 1;
	further_calculation(walls);
}
