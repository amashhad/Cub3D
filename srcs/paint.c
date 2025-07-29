/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:05:26 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/29 15:17:08 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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

	i = 10000;
	if (data->is_mouse_down && ((x > 324 && x < 930) && (y > 226 && y < 625)))
	{
		while (i >= data->font_size)
		{
			mlx_string_put(data->mlx, data->window, rand()/100 + i, rand()*100 - i, 0x00FF00, "0");
			mlx_string_put(data->mlx, data->window, rand()/100 - i, rand()*100 + i, 0x00FF00, "1");
			i--;
		}
		i = 10000;
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
	if (button == XK_b && data->font_size > 0)
			data->font_size--;
	if (button == XK_r)
			data->font_size = 0;
	printf("Font size is now %d\n", data->font_size);
	return (0);
}
