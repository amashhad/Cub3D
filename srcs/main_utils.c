/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 20:21:37 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 22:05:10 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void draw_vision(t_data *data, t_algo *algo)
{
	algo->y1 = (int)data->player->player_y;
	algo->x1 = (int)data->player->player_x;
	algo->angle = atan2(data->player->dir_y, data->player->dir_x);
	project_walls(algo, data->walls, data);
}


void	free_keys(t_data *data)
{
	int	i;

	i = 0;
	mlx_destroy_window(data->mlx, data->screen->screen_thrd);
	mlx_destroy_image(data->mlx, data->middle);
	while (i < 4)
	{
		mlx_destroy_image(data->mlx, data->texture[i].img);
		i++;
	}
	mlx_destroy_display(data->mlx);
	dynamic_free("%a%f%f%f%f%f%f%f", data->mdata->arr_map,
		data->mdata, data->player, data->screen, data->mlx, data->algo, data->walls, data);
	exit(0);
}

int keys(int key, t_data *data)
{
	if (key == XK_Escape)
		free_keys(data);
	if (x_axis(key, data))
		return (0);
	if (y_axis(key, data))
		return (0);
	if (key == XK_e || key == XK_E)
		rotate_player(data->player, -0.2222); // rotate right
	if (key == XK_q || key == XK_Q)
		rotate_player(data->player, 0.2222); // rotate left
	mlx_clear_window(data->mlx, data->screen->screen_thrd);
	bg_img(data, 0xFFFFFF, 0x287337);
	draw_vision(data, data->algo);
	mlx_put_image_to_window(data->mlx, data->screen->screen_thrd, data->middle, 0, 0); //background
	return (1);
}
