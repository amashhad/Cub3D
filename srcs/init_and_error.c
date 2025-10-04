/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_error.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:33:11 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 20:16:53 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
void    init_map(t_map *map)
{
    map->arr_map = NULL;
    map->img_ea = NULL;
    map->img_no = NULL;
    map->img_so = NULL;
    map->img_we = NULL;
    map->int_ea = 0;
    map->int_no = 0;
    map->int_so = 0;
    map->int_we = 0;
    map->ceiling_blue = -1;
    map->ceiling_red = -1;
    map->ceiling_green = -1;
    map->floor_blue = -1;
    map->floor_green = -1;
    map->floor_red = -1;
    map->player = 0;
    map->cols = 0;
    map->rows = 0;
	map->out_border = 0;
	map->number_img = 0;
	map->index_map = 0;
	map->index_line = 0;
	map->x_player = 0;
	map->y_player = 0;
    map->player_orien = '\0';
}
void    map_error_2(t_map *map)
{
    if (map->img_so)
    {
        free (map->img_so);
        map->img_so = NULL;
    }
    if (map->img_we)
    {
        free (map->img_we);
        map->img_we = NULL;
    }
    if (map->img_ea)
    {
        free (map->img_ea);
        map->img_ea = NULL;
    }
}
void    map_error(t_map *map, int error)
{
    if (map)
    {
        if (map->arr_map)
        {
            ft_farray(map->arr_map);
        }
        if (map->img_no)
        {
            free (map->img_no);
            map->img_no = NULL;
        }
        map_error_2(map);
        free (map);
    }
    if (error)
    {
        ft_putendl_fd("map error", 2);
        exit(1);
    }
}
