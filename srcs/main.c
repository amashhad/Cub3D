/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:41:53 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:34:04 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	create_map_buffer(t_data *data)
{
	data->virtual = ft_calloc(sizeof(t_virtual), 1);
	data->virtual->img = mlx_new_image(data->mlx, data->screen->height, data->screen->width);
	data->virtual->v_map = mlx_get_data_addr(data->virtual->img, &data->virtual->bpp, &data->virtual->line_len, &data->virtual->endean);

	for (int y = 0; y < 9; y++)
	{
		for (int x = 0; x < 13; x++)
		{
			if (data->map->arr_map[y][x] == 'P')
			{
				data->player->player_x = x * TILE_SIZE;
				data->player->player_y = y * TILE_SIZE;
			}
			int color = (data->map->arr_map[y][x] == '1') ? 0x00FFFFFF : 0x00000000; // wall = white, empty = black
			for (int py = 0; py < TILE_SIZE; py++)
			{
				for (int px = 0; px < TILE_SIZE; px++)
				{
					int pixel_x = x * TILE_SIZE + px;
					int pixel_y = y * TILE_SIZE + py;
					if (pixel_x < data->screen->width && pixel_y < data->screen->height)
					{
						char *dst = data->virtual->v_map + (pixel_y * data->virtual->line_len + pixel_x * (data->virtual->bpp / 8));
						*(unsigned int*)dst = color;
					}
				}
			}
		}
	}
}

//draws the cone, input length
void draw_vision(t_data *data, int length)
{
	int		ray_index;

	ray_index = 0;
	data->algo->y1 = (int)data->player->player_y;
	data->algo->x1 = (int)data->player->player_x;
	data->algo->angle = atan2(data->player->dir_y, data->player->dir_x); // get facing angle from direction vector
	//int rays_total = (int)( (fov * 2) / step ) + 1;
	setup_algo(data, length);
	ray_index++;
}



void	create_map(t_data *data)
{
	data->map->arr_map = malloc(sizeof(char *) * 1);
	data->map->arr_map[0] = NULL;
	data->map->arr_map = ft_addarr("1111111111111", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000000001", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000000001", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000000001", data->map->arr_map);
	data->map->arr_map = ft_addarr("111000P000111", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000010011", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000000001", data->map->arr_map);
	data->map->arr_map = ft_addarr("1000000000001", data->map->arr_map);
	data->map->arr_map = ft_addarr("1111111111111", data->map->arr_map);
	ft_addprintarr("map: ", data->map->arr_map);
}

int	keys(int key, t_data *data)
{
	if (key == XK_Escape)
		return (dynamic_free("%a%f%f%f%f%f%f%f%e", data->map->arr_map, data->map,
			data->player, data->algo, data->virtual, data->screen, data->mlx,
				data, mlx_destroy_image(data->mlx, data->virtual->img),
					mlx_destroy_window(data->mlx, data->win),
					mlx_destroy_display(data->mlx), mlx_loop_end(data->mlx)));
	if (x_axis(key, data))
			return (0);
	if (y_axis(key, data))
			return (0);
	if (key == XK_e || key == XK_E)
    	rotate_player(data->player, -0.2222); // rotate right
	if (key == XK_q || key == XK_Q)
    	rotate_player(data->player, 0.2222);  // rotate left
	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win, data->virtual->img, 0, 0);
	draw_vision(data, 200);
	custom_putpixel(data);
	return (1);
}

int	main(void)
{
	//allocation
	t_data *data;

	data = ft_calloc(sizeof(t_data ), 1);
	if (!data)
		exit(1);
	allocate_structs(data);
	setup_position(data);
	mlx_setup(data);
	//data_proccessing
	create_map(data); //creates map
	create_map_buffer(data);//creates buffer for the map to set it up
	mlx_put_image_to_window(data->mlx, data->win, data->virtual->img, 0, 0);
	algo_param(data);
	draw_vision(data, 200);
	custom_putpixel(data); //custom putpixel to create the player approprietly
	mlx_hook(data->win, 2, 1L<<0, keys, data); //movement and quit
	mlx_loop(data->mlx);//loop
}
