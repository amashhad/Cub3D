/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 06:31:44 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:34:21 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	x_axis(int key, t_data *data)
{
	if (key == XK_a || key == XK_A)
	{
		if (data->map->arr_map[((int)data->player->player_y)/TILE_SIZE][((int)data->player->player_x - 10)/TILE_SIZE] == '1')
			return (1);
		data->player->player_x-=10;
	}
	if (key == XK_d || key == XK_D)
	{
		if (data->map->arr_map[((int)data->player->player_y)/TILE_SIZE][((int)data->player->player_x + 10)/TILE_SIZE] == '1')
			return (1);
		data->player->player_x+=10;
	}
	return (0);
}

int	y_axis(int key, t_data *data)
{
	if (key == XK_w || key == XK_W)
	{
		if (data->map->arr_map[((int)data->player->player_y -10)/TILE_SIZE][((int)data->player->player_x)/TILE_SIZE] == '1')
			return (1);
		data->player->player_y-=10;
	}
	if (key == XK_s || key == XK_S)
	{
		if (data->map->arr_map[((int)data->player->player_y + 10)/TILE_SIZE][((int)data->player->player_x)/TILE_SIZE] == '1')
			return (1);
		data->player->player_y+=10;
	}
	return (0);
}
