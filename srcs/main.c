/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:35:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/27 22:32:47 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <X11/keysym.h>

int	exit_func(int button, t_data *data)
{
	if (button == XK_Escape)
		mlx_loop_end(data->mlx);
	if (button == XK_c)
		mlx_clear_window(data->mlx, data->window);
	return (0);
}
int	is_pressed(int button)
{
	if (button == 1)
		return (1);
	return (0);
}

int		mouse_release(int button, int x, int y, t_data *data)
{
	if (button == 1)
	{
		data->is_mouse_down = 0;
		printf("Mouse released at (%d, %d)\n", x, y);
	}
	return (0);
}

int	mouse_press(int button, int x, int y, t_data *data)
{
	if (button == 1) // Left click
	{
		data->is_mouse_down = 1;
		printf("Mouse pressed at (%d, %d)\n", x, y);
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	int i;

	i = -1;
	if (data->is_mouse_down)
	{
		while (i < data->font_size)
		{
			mlx_string_put(data->mlx, data->window, x + i, y - i, 0xD4AF37, "0");
			i++;
		}
		i = -1;
			printf("Mouse move while pressed at (%d, %d)\n", x, y);
	}
	return (0);
}
int	font_resize(int button, t_data *data)
{
	if (button == XK_a)
	{
		data->font_size++;
	}
	else if (button == XK_b && data->font_size > 0)
			data->font_size--;
	printf("Font size is now %d\n", data->font_size);
	return (0);
}

int	main(void)
{
	t_data *data;

	data = calloc(sizeof(t_data), 1);
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
	mlx_hook(data->window, 2, 1L << 0, exit_func, data);
	mlx_key_hook(data->window, font_resize, data);
	mlx_mouse_hook(data->window, mouse_press, data);
	mlx_hook(data->window, 5, 1L << 3, mouse_release, data);
	mlx_hook(data->window, 6, 1L << 6, mouse_move, data);
	mlx_loop(data->mlx);
	return (0);
}
