/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:35:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/08/22 01:26:43 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"
#include <X11/keysym.h>
#include <math.h>

int	mouse_tracker(t_data *data)
{
	int x = 0;
	int y = 0;
	mlx_mouse_get_pos(data->mlx, data->screen->screen, &x, &y);
	printf("x: %dy: %d\n", x, y);
	return (1);
}

int	exit_game(t_data *data)
{
	mlx_loop_end(data->mlx);;
	return (1);
}

int	exit_func(int keycode, t_data *data)
{
	if (keycode == XK_Escape || keycode == XK_q || keycode == XK_Q)
	{
		exit_game(data);
	}
	if (keycode == XK_g || keycode == XK_G)
		mouse_tracker(data);
	return (0);
}

int	flagx(t_data *data, float x)
{
	for (size_t i = 0; i > ft_strlen(data->map->arr_map[0]); i++)
	{
		if ((data->flagx[i] <= x + 1) && ((data->flagx[i] >= x - 1)))
			return (0);
	}
	return (1);
}

int	flagy(t_data *data, float y)
{
	printf("%zu\n", ft_strlen(data->map->arr_map[0]));
	for (size_t i = 0; i > ft_strlen(*data->map->arr_map); i++)
	{
		printf("a%fa", data->flagy[i]);
		if ((data->flagy[i] <= y + 1) && ((data->flagy[i] >= y - 1)))
			return (0);
	}
	return (1);
}

void DDA(t_data *data, int X0, int Y0, int X1, int Y1)
{
    // calculate dx & dy
    int dx = X1 - X0;
    int dy = Y1 - Y0;

    // calculate steps required for generating pixels
    int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);

    // calculate increment in x & y for each steps
    float Xinc = dx / (float)steps;
    float Yinc = dy / (float)steps;

    // Put pixel for each step
    float X = X0;
    float Y = Y0;
    for (int i = 0; i <= steps; i++)
	{
		printf("%d, %d\n", (int)round(X) / 216,(int)round(Y) / 192);
		if (X < 900 && data->map->arr_map[(int)round(X) / 216][(int)round(Y) / 192] != '0')
		{
			//printf("realx: %f realy:%f\n", X, Y);
			mlx_pixel_put(data->mlx, data->screen->screen,round(X), round(Y), 4425203); // put pixel at (X,Y)
		}
		else
			printf("didn't print");
        X += Xinc; // increment in x at each step
        Y += Yinc; // increment in y at each step
        //delay(100); // for visualization of line-
                    // generation step by step
    }
}

void	assign_flags(t_data *data)
{
	int	i = 0;
	int	j = 0;
	int	k = 0;

	data->flagx = ft_calloc(sizeof(int ), (ft_strlen(data->map->arr_map[0]) * (ft_arrlen(data->map->arr_map))));
	data->flagy = ft_calloc(sizeof(int ), (ft_strlen(data->map->arr_map[0]) * (ft_arrlen(data->map->arr_map))));
	for (; (size_t)i < ft_strlen(data->map->arr_map[i]); i++)
	{
		while (data->map->arr_map[i][j] != '\0')
		{
			if (data->map->arr_map[i][j] == '1')
			{
				data->flagx[k] = i * 216;
				data->flagy[k] = j * 192;
				printf("%d:%d\n", i, j);
				printf("%d: x:%f y:%f\n", k, data->flagx[k], data->flagy[k]);
				k++;
			}
			j++;
		}
		j = 0;
	}
}

void	read_map(t_data *data)
{
	parser(data);
	assign_flags(data);
}

//line len = len/screen_width
int	main(void)
{
	t_data *data;

	data = ft_calloc(sizeof(t_data), 1);
	data->screen = ft_calloc(sizeof(t_screen),  1);
	//parser(data);
	data->mlx = mlx_init();
	mlx_get_screen_size(data->mlx, &data->screen->height, &data->screen->width);
	read_map(data);
	data->screen->screen = mlx_new_window(data->mlx, data->screen->height, data->screen->width, "Test");
	for (int i = 0; i < data->screen->height; i++)
	{
		// DDA(data, 901, 603, i, 0);
		// DDA(data, 0, 603, i, 603);
		// DDA(data, 901, i, 901, 0);
		DDA(data, 0, 0, i, data->screen->width);
		DDA(data, 0, 0, data->screen->height, i);
	}
	mlx_hook(data->screen->screen, 2, 1L<<0, exit_func, data);
	mlx_loop(data->mlx);
	return (0);
}
