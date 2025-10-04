/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_save_search.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:41:01 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 05:32:22 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

void	map_read(char *file, t_map *map)
{
	char	*line;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map, 1);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
        if (line[ft_strlen(line) - 1] == '\n')
            line[ft_strlen(line) - 1] = '\0';
        if (check_form(map, line))
		{
			free(line);
            map_error(map, 1);
		}
		free(line);
		map->index_line++;
	}
	close(fd);
}

void	continue_save(int fd, t_map *map, char *line, int i)
{
	while (i < map->index_map)
	{
		line = get_next_line(fd);
		free (line);
		i++;
	}
	i = 0;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		map->arr_map[i] = ft_strdup(line);
		free(line);
		if (!map->arr_map[i])
			map_error(map, 1);
		i++;
	}
	map->arr_map[i] = NULL;
}

void	map_save(char *file, t_map *map)
{
	char	*line;
	int		i;
	int		fd;

	line = NULL;
	i = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		map_error(map, 1);
	map->arr_map = (char **)malloc((map->rows + 1) * sizeof(char *));
	if (!map->arr_map)
		map_error(map, 1);
	continue_save(fd, map, line, i);
	close(fd);
}

