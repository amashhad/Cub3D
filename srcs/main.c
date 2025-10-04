/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 00:41:53 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 22:02:53 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	get_data(t_data *data, t_map *map)
{
	data->mdata->arr_map = ft_cpyarr(map->arr_map);
	data->mdata->img_ea = ft_strdup(map->img_ea);
	data->mdata->img_no = ft_strdup(map->img_no);
	data->mdata->img_so = ft_strdup(map->img_so);
	data->mdata->img_we = ft_strdup(map->img_we);
	data->mdata->floor_blue = map->floor_blue;
	data->mdata->floor_red = map->floor_red;
	data->mdata->floor_green = map->floor_green;
	data->mdata->ceiling_blue = map->ceiling_blue;
	data->mdata->ceiling_red = map->ceiling_red;
	data->mdata->ceiling_green = map->ceiling_green;
	data->mdata->map_row = map->rows;
	data->mdata->map_coln = map->cols;
	data->mdata->player_pos = map->player_orien;
}

void	go_to_work(t_data *data, t_map *map)
{
	allocate_structs(data);
	get_data(data, map);
	map_error(map, 0);
	setup_position(data, data->mdata);
	mlx_setup(data);
	mount_middle(data);
	algo_param(data->algo);
	data->mdata->ceiling_color = ((data->mdata->ceiling_red << 16)
			| (data->mdata->ceiling_green << 8)
			| data->mdata->ceiling_blue);
	data->mdata->floor_color = ((data->mdata->floor_red << 16)
			| (data->mdata->floor_green << 8)
			| data->mdata->floor_blue);;
	bg_img(data, data->mdata->ceiling_color, data->mdata->floor_color);
	draw_vision(data, data->algo);
}

int main(int argc, char **argv)
{
	t_data	*data;
	t_map   *map;

    map = malloc(sizeof(t_map));
    if (!map)
    {
        ft_putendl_fd("Error in malloc", 2);
		exit(1);
    }
	main_map(map, argc, argv);
	data = ft_calloc(1, sizeof(t_data));
	if (!data)
		exit(1);
	go_to_work(data, map);
	mlx_put_image_to_window(data->mlx, data->screen->screen_thrd, data->middle, 0, 0);
	mlx_hook(data->screen->screen_thrd, 2, 1L << 0, keys, data);
	mlx_loop(data->mlx);
	return (0);
}
