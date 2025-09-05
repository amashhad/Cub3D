/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paint.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 15:05:26 by amashhad          #+#    #+#             */
/*   Updated: 2025/08/10 18:41:55 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <math.h>

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

void draw_line(t_data *data, int x1, int y1, int x2, int y2)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx = x1 < x2 ? 1 : -1;
	int sy = y1 < y2 ? 1 : -1;
	int err = dx - dy;

	while (1)
	{
		mlx_pixel_put(data->mlx, data->window, x1, y1, 0xFFFFFF);
		if (x1 == x2 && y1 == y2)
			break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

void draw_cube(t_data *data, int x, int y, int size, int depth)
{
	// Front face
	int fx1 = x;
	int fy1 = y;
	int fx2 = x + size;
	int fy2 = y + size;

	// Back face (offset for depth)
	int bx1 = fx1 + depth;
	int by1 = fy1 - depth;
	int bx2 = fx2 + depth;
	int by2 = fy2 - depth;

	// Draw front square
	draw_line(data, fx1, fy1, fx2, fy1); // top
	draw_line(data, fx2, fy1, fx2, fy2); // right
	draw_line(data, fx2, fy2, fx1, fy2); // bottom
	draw_line(data, fx1, fy2, fx1, fy1); // left

	// Draw back square
	draw_line(data, bx1, by1, bx2, by1); // top
	draw_line(data, bx2, by1, bx2, by2); // right
	draw_line(data, bx2, by2, bx1, by2); // bottom
	draw_line(data, bx1, by2, bx1, by1); // left

	// Connect corners
	draw_line(data, fx1, fy1, bx1, by1); // top-left
	draw_line(data, fx2, fy1, bx2, by1); // top-right
	draw_line(data, fx2, fy2, bx2, by2); // bottom-right
	draw_line(data, fx1, fy2, bx1, by2); // bottom-left
}

void draw_sqr(t_data *data, int x, int y, int size)
{
	draw_line(data, x, y, x + size, y);
	draw_line(data, x, y, x, y + size);
	draw_line(data, x + size, y, x + size, y + size);
	draw_line(data, x, y + size, x + size, y + size);
}
int	paint_3d(int x, int y, int x2, int y2, t_data *data)
{
	//assume x2 = x + 25, y2 = y + 25
	float	m = 0;
	float	dx = 0;
	float	dy = 0;
	float	yz = 0;
	int	i = x;
	dx = fabsf((float)x - (float)x2);
	dy = fabsf((float)y - (float)y2);
	m = dy/dx;
	while (i <= x2)
	{
		yz = y + m * (i - x);
		mlx_pixel_put(data->mlx, data->window, i, (int)roundf(yz), 255);
		i++;
	}
	return (0);
}

int	mouse_move(int x, int y, t_data *data)
{
	//assume x2 = x + 25, y2 = y + 25
	float	m = 0;
	float	dx = 0;
	float	dy = 0;
	float	yz = 0;
	int	x2 = x + 150;
	int y2 = y + 150;
	int	i = x;
	draw_cube(data, x, y, x2, y2);
	if (data->is_mouse_down == 1)
	{
		dx = fabsf((float)x - (float)x2);
		dy = fabsf((float)y - (float)y2);
		m = dy/dx;
		while (i <= x2)
		{
			yz = y + m * (i - x);
			mlx_pixel_put(data->mlx, data->window, i, (int)roundf(yz), 255);
			i++;
		}
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
