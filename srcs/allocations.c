/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:36:17 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 20:27:04 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	allocate_structs(t_data *data)//////////////////
{
	data->screen = ft_calloc(1, sizeof(t_screen ));
	if (!data->screen)
		dynamic_free("%f%s%e", data, "data->screen fail\n", 1);
	data->player = ft_calloc(1, sizeof(t_player ));
	if (!data->player)
		dynamic_free("%f%f%s%e", data->screen, data, "data->player fail\n", 1);
	data->mdata = ft_calloc(1, sizeof(t_map ));
	if (!data->mdata)
		dynamic_free("%f%f%f%s%e", data->screen
				, data->player, data, "data->map fail\n", 1);
	data->algo = ft_calloc(1, sizeof(t_algo ));
	if (!data->algo)
		dynamic_free("%f%f%f%f%s%e", data->screen
				, data->player, data, data->mdata, "data->algo fail\n", 1);
	data->walls = ft_calloc(1, sizeof(t_walls ));
	if (!data->walls)
			dynamic_free("%f%f%f%f%f%s%e", data->screen
				, data->player, data, data->mdata, data->algo, "data->algo fail\n", 1);
	data->player->speed = 10;
}

