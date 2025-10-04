/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:52:20 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 21:54:55 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	safe_exit(t_data *data, int	status)
{
	free(data->player);
	free(data->mdata);
	free(data->screen);
	free(data);
	exit(status);
}

void	imgs(t_data *data)
{
	int		i;

	i = 0;
	while (i < 4)
	{
		ft_bzero(&data->texture[i], sizeof(t_texture));
		i++;
	}
	i = 0;
	data->texture[0].img = mlx_xpm_file_to_image(data->mlx, "/home/amashhad/sgoinfre/new_3d/assets/player.xpm", &data->texture[0].width, &data->texture[0].height);
	data->texture[1].img = mlx_xpm_file_to_image(data->mlx, "/home/amashhad/sgoinfre/new_3d/assets/player.xpm", &data->texture[1].width, &data->texture[1].height);
	data->texture[2].img = mlx_xpm_file_to_image(data->mlx, "/home/amashhad/sgoinfre/new_3d/assets/player.xpm", &data->texture[2].width, &data->texture[2].height);
	data->texture[3].img = mlx_xpm_file_to_image(data->mlx, "/home/amashhad/sgoinfre/new_3d/assets/player.xpm", &data->texture[3].width, &data->texture[3].height);
	while (i < 4)
	{
		data->texture[i].addr = mlx_get_data_addr(data->texture[i].img,
				&data->texture[i].bpp,
				&data->texture[i].len,
				&data->texture[i].endean);
		i++;
	}
}


void	mlx_setup(t_data *data)
{
	int	scale;

	data->mlx = mlx_init();
	if (!data->mlx)
		dynamic_free("%a%f%f%f%f%f%f%f%f", data->mdata->arr_map,
			data->mdata, data->screen, data->player, data->algo, data->walls, data);
	mlx_get_screen_size(data->mlx, &data->screen->width, &data->screen->height); //gets screen size
	data->screen->width /=2;
	data->screen->height /=2;
	scale = fmin(data->screen->width/data->mdata->map_row, data->screen->height/data->mdata->map_coln);
	data->screen->screen_thrd = mlx_new_window(data->mlx, (data->screen->width), (data->screen->height), "3D screen");
	imgs(data);
}
