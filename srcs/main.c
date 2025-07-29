/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:35:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/28 16:47:33 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <X11/keysym.h>

int	exit_func(int button, t_data *data)
{
	if (button == XK_Escape)
	{
		mlx_destroy_window(data->mlx ,data->window);
		mlx_loop_end(data->mlx);
		free(data);
	}
	if (button == XK_c)
	{
		mlx_clear_window(data->mlx, data->window);
		mlx_put_image_to_window(data->mlx, data->window, data->screen->canva, 320, 220);
	}
	return (0);
}


int	main(void)
{
	t_data *data;
	int		height;
	int 	width;

	data = calloc(sizeof(t_data), 1);
	data->screen = calloc(sizeof(t_data), 1);
	if (!data)
		return (1);
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(data);
		return (1);
	}
	data->window = mlx_new_window(data->mlx, 1280, 1080, "Cub3D");
	if (!data->window)
	{
		free(data);
		return (1);
	}
	data->screen->canva = mlx_xpm_file_to_image(data->mlx, "assets/canvas.xpm", &width, &height);
	mlx_put_image_to_window(data->mlx, data->window, data->screen->canva, 320, 220);
	mlx_do_sync(data->mlx);

	mlx_hook(data->window, 2, 1L << 0, exit_func, data);
	mlx_key_hook(data->window, font_resize, data);
	mlx_mouse_hook(data->window, mouse_press, data);
	mlx_hook(data->window, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->window, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx);
	return (0);
}
