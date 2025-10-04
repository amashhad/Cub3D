/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_cols.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:42:53 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 20:16:24 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	get_cols(t_map *map)
{
	int	i;
	size_t	great;
	size_t	lower;

	i = 0;
	great = ft_strlen(map->arr_map[i]);
	i++;
	while (map->arr_map[i])
	{
		lower = ft_strlen(map->arr_map[i]);
		if (lower > great)
			great = lower;
		i++;
	}
	map->cols = great;
	return ;
}

void	search_player(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->arr_map[i])
	{
		j = 0;
		while (map->arr_map[i][j] != '\0')
		{
			if (char_valid_player(map, map->arr_map[i][j]))
			{
				map->x_player = j;
				map->y_player = i;
				map->player_orien = map->arr_map[i][j];
				return ;
			}
			j++;
		}
		i++;
	}

}
