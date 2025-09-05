/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocations.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 00:36:17 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 06:24:15 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	allocate_structs(t_data *data)
{
	data->screen = ft_calloc(sizeof(t_screen ), 1);
	if (!data->screen)
		dynamic_free("%f%s%e", data, "data->screen fail\n", 1);
	data->player = ft_calloc(sizeof(t_player ), 1);
	if (!data->player)
		dynamic_free("%f%f%s%e", data->screen, data, "data->player fail\n", 1);
	data->map = ft_calloc(sizeof(t_map ), 1);
	if (!data->map)
		dynamic_free("%f%f%f%s%e", data->screen
				, data->player, data, "data->map fail\n", 1);
	data->algo = ft_calloc(sizeof(t_algo ), 1);
	if (!data->algo)
		dynamic_free("%f%f%f%s%e", data->map
					, data->screen, data->player, data, "data->algo fail\n", 1);
}

