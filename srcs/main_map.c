/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:58:10 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 21:53:35 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

static void	check_path(t_map *map, int i, int j)
{
	if (map->arr_map[i][j] == '1' || map->arr_map[i][j] == 'F')
		return ;
	if (map->arr_map[i][j] == ' ' || (i == map->rows - 1 && map->arr_map[i][j] == '0') || (j == skip_space_bake(map->arr_map[i]) && map->arr_map[i][j] == '0') || (i == 0  && map->arr_map[i][j] == '0')
		|| (j == skip_space_front(map->arr_map[i]) && map->arr_map[i][j] == '0') || map->arr_map[i][j] == '\0')
		map_error(map, 1);
	map->arr_map[i][j] = 'F';
	check_path(map, i - 1, j);
	check_path(map, i, j + 1);
	check_path(map, i + 1, j);
	check_path(map, i, j - 1);
	check_path(map, i - 1, j - 1);
	check_path(map, i + 1, j - 1);
	check_path(map, i + 1, j + 1);
	check_path(map, i - 1, j + 1);
}

void	map_check(t_map *map)
{
	int	i;

	i = 0;
	if (map->player > 1 || map->player == 0)
		map_error(map, 1);
	search_player(map);
	get_cols(map);
	while (map->arr_map[i])
	{
		if (map->y_player == map->rows - 1 || (map->x_player == skip_space_bake(map->arr_map[i]) && i == map->y_player) || map->y_player == 0
			|| (map->x_player == skip_space_front(map->arr_map[i]) && i == map->y_player))
			map_error(map, 1);
		i++;
	}

	check_path(map, map->y_player, map->x_player);
}

static void	check_args(t_map *map, int argc, char **argv)
{
	int		fd;

	if (argc != 2)
	{
		ft_printf("Wrong Number of Arguments :(\n");
		map_error(map, 1);
	}
	if (ft_strrchr(argv[1], '.'))
	{
		if (ft_strcmp(ft_strchr(argv[1], '.'), ".cub"))
			map_error(map, 1);
		fd = open(argv[1], O_RDONLY);
		if (fd == -1)
		{
			ft_putendl_fd("Map File not found :(\n", 2);
			map_error(map, 1);
		}
		close(fd);
	}
	return ;
}

int	main_map(t_map *map, int argc, char **argv)
{
	check_args(map, argc, argv);
	init_map(map);
	map_read(argv[1], map);
	map_save(argv[1], map);
	map_check(map);
	return (0);
}
