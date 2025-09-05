/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enviroment.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/08 03:53:13 by amashhad          #+#    #+#             */
/*   Updated: 2025/08/10 21:49:53 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	mount_img(t_data *data)
{
	int	w;
	int	h;

	data->map->east = mlx_xpm_file_to_image(data->mlx, "assets/East.xpm", &w, &h);
	data->map->west = mlx_xpm_file_to_image(data->mlx, "assets/West.xpm", &w, &h);
	data->map->south = mlx_xpm_file_to_image(data->mlx, "assets/South.xpm", &w, &h);
	data->map->north = mlx_xpm_file_to_image(data->mlx, "assets/North.xpm", &w, &h);
}

void	mount_map(t_data *data)
{
	int	trigg = 0;
	data->player = ft_calloc(sizeof(t_player), 1);
	data->trigger->trigger = ft_calloc(sizeof(int), (60));
	for (int i = 0; data->map->map[i]; i++)
	{
		for (int j = 0; data->map->map[i][j]; j++)
		{
			printf("i:%d\nj:%d\n", i, j);
			if (data->map->map[i][j] == '1')
			{
				data->trigger->trigger[trigg] = i;
				trigg++;
				data->trigger->trigger[trigg] = j;
				trigg++;
				draw_sqr(data, i * SIZE, j * SIZE, SIZE);
			}
			else if (data->map->map[i][j] == 'P')
			{
				draw_sqr(data, i * SIZE + (SIZE / 2), j * SIZE + (SIZE / 2), SIZE / 10);
				data->player->player_x = i;
				data->player->player_y = j;
			}
		}
	}

	for (int i = 0; i < data->screen->height; i++)
	{
		paint_3d( data->player->player_x, data->player->player_y, i * SIZE, i * SIZE, data);
	}
// 	int tile_size = 256; // same as in mlx_put_image_to_window()
// 	int px = data->player->player_y * tile_size;
// 	int py = data->player->player_x * tile_size;
// 	for (int i = 0; data->map->map[i]; i++)
// 	{
// 		for (int j = 0; data->map->map[i][j]; j++)
// 		{
// 			printf("i:%d\nj:%d\n", i, j);
// 			if (data->map->map[i][j] == '1' && i  < 2)
// 			{
// 				paint_3d((px), (py), ( i * 256), (j * 256), data);
// 			}
// 			else if (data->map->map[i][j] == '1' && (i == 2 && j < 2))
// 			{
// 				paint_3d((px), (py), ( i * 256), (j * 256), data);
// 			}
// 			else if (data->map->map[i][j] == '1' && (i == 2 && j > 2))
// 			{
// 				paint_3d((px), (py), ( i * 256), (j * 256), data);
// 			}
// 			else if (data->map->map[i][j] == '1' && i > 2)
// 			{
// 				paint_3d((px), (py), ( i * 256), (j * 256), data);
// 			}
// 		}
// 	}
}

// void draw_ray(t_data *data)
// {

// }

void	*enviroment(t_data *data)
{
	data->map->map = malloc(sizeof(char *) * (1));
	data->map->map[0] = NULL;
	data->map->map = ft_addarr(ft_strdup("1111111"), data->map->map);
	data->map->map = ft_addarr(ft_strdup("1110111"), data->map->map);
	data->map->map = ft_addarr(ft_strdup("110P011"), data->map->map);
	data->map->map = ft_addarr(ft_strdup("1110111"), data->map->map);
	data->map->map = ft_addarr(ft_strdup("1111111"), data->map->map);
	ft_printarr(data->map->map);
	mount_img(data);
	mount_map(data);
	return (NULL);
}
