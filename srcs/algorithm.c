/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 02:50:28 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:25:06 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	draw_algo(t_data *data)
{
	int	e2;

	e2 = 2 * data->algo->err;
	while (1)
	{
		mlx_pixel_put(data->mlx, data->win, data->algo->cx, data->algo->cy, 0xFF12);
		if ((data->algo->cx == data->algo->x2 && data->algo->cy == data->algo->y2)
				|| data->map->arr_map[data->algo->cy/TILE_SIZE][data->algo->cx/TILE_SIZE] == '1')
			break;
		if (e2 > -data->algo->dy)
		{
			data->algo->err -= data->algo->dy;
			data->algo->cx += data->algo->sx;
		}
		if (e2 < data->algo->dx)
		{
			data->algo->err += data->algo->dx;
			data->algo->cy += data->algo->sy;
		}
		e2 = 2 * data->algo->err;
	}
}
void	algo_param(t_data *data)
{
	// cone parameters
	data->algo->fov = PI / 8;        // 22.5° to each side = 45° cone
	data->algo->step = PI / 360;     // 1° step (smaller = smoother cone, but more rays)
}

void	setup_algo(t_data *data, int length)
{
	double	a;

	a = -data->algo->fov;
	// cast many rays inside cone
	while (a <= data->algo->fov)
	{
		data->algo->ray_angle = data->algo->angle + a;
		data->algo->x2 = data->algo->x1 + cos(data->algo->ray_angle) * length;
		data->algo->y2 = data->algo->y1 + sin(data->algo->ray_angle) * length;
		// --- Bresenham line per ray ---
		data->algo->dx = abs(data->algo->x2 - data->algo->x1);
		data->algo->dy = abs(data->algo->y2 - data->algo->y1);
		if (data->algo->x1 < data->algo->x2)
			data->algo->sx = 1;
		else
			data->algo->sx = -1;
		if (data->algo->y1 < data->algo->y2)
			data->algo->sy = 1;
		else
			data->algo->sy = -1;
		data->algo->err = data->algo->dx - data->algo->dy;
		data->algo->cx = data->algo->x1;
		data->algo->cy = data->algo->y1;
		draw_algo(data);
		a += data->algo->step;
	}
}
