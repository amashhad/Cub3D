/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:39:46 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 20:49:15 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_position(t_data *data, t_mdata *map)
{
	if (map->player_pos == 'N')
	{
		data->player->dir_x = 0;
		data->player->dir_y = -1;
	}
	else if (map->player_pos == 'E')
	{
		data->player->dir_x = 1;
		data->player->dir_y = 0;
	}
	else if (map->player_pos == 'S')
	{
		data->player->dir_x = 0;
		data->player->dir_y = 1;
	}
	else if (map->player_pos == 'W')
	{
		data->player->dir_x = -1;
		data->player->dir_y = 0;
	}
}

void rotate_player(t_player *player, double angle)
{
	double old_x;

	old_x = player->dir_x;
	player->dir_x = player->dir_x * cos(angle) - player->dir_y * sin(angle);
	player->dir_y = old_x * sin(angle) + player->dir_y * cos(angle);
}
