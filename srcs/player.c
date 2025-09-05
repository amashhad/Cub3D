/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:39:46 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:25:20 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	setup_position(t_data *data)
{
	//player looking up (N)
	data->player->dir_x = 0;
	data->player->dir_y = -1;
}

void rotate_player(t_player *p, double angle)
{
    double old_x = p->dir_x;

    p->dir_x = p->dir_x * cos(angle) - p->dir_y * sin(angle);
    p->dir_y = old_x * sin(angle) + p->dir_y * cos(angle);
}

void	custom_putpixel(t_data *data)
{
	int	i;
	int	j;

	i = -5;
	j = -5;
	if (data->player->player_x >= (data->screen->height - 5)
			|| data->player->player_y >= (data->screen->width - 5)
			|| data->player->player_x == 5 || data->player->player_y == 5)
		return ;
	while (i < 5)
	{
		while (j < 5)
		{
			mlx_pixel_put(data->mlx, data->win, (data->player->player_x + j), (data->player->player_y + i), 0xFF);
			j++;
		}
		i++;
		j = -5;
	}
}
