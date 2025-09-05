/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:52:20 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:24:52 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	safe_exit(t_data *data, int	status)
{
	free(data->player);
	free(data->map);
	free(data->screen);
	free(data);
	exit(status);
}
void	mlx_setup(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		dynamic_free("%f%f%f%f%f%s%e", data->algo, data->player,
				data->screen, data->map, data, "MLX init alloc failed\n", 1);
	mlx_get_screen_size(data->mlx, &data->screen->height, &data->screen->width); //gets screen size
	data->screen->height /=2;
	data->screen->width /=2;
	data->win = mlx_new_window(data->mlx, data->screen->height,data->screen->width, "cub3d");
	if (!data->win)
		dynamic_free("%f%f%f%f%f%f%s%e", data->algo, data->player, data->screen
				, data->map, data->mlx, data, "MLX win alloc failed\n"
				, (mlx_destroy_display(data->mlx) + 1));
	//data->screen->screen_thrd = mlx_new_window(data->mlx, (data->screen->height), (data->screen->width), "3D screen");
}
