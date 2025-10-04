/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_and_first_skip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:35:33 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 05:32:57 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
void    fill_color_of_floor(t_map *map, char **log)
{
    map->floor_red = ft_atoi(log[0]);
    map->floor_green = ft_atoi(log[1]);
    map->floor_blue = ft_atoi(log[2]);
}

void    fill_color_of_ciling(t_map *map, char **log)
{
    map->ceiling_red = ft_atoi(log[0]);
    map->ceiling_green = ft_atoi(log[1]);
    map->ceiling_blue = ft_atoi(log[2]);
}

char	*skip_revers(char *line)
{
	size_t	i;

	i = 0;
	if (line[i] == '\0' || line[i] == '\n')
		return (line);
	i = ft_strlen(line) - 1;
	if (!is_space(line[i]))
		return (line);
	while (i > 0 && is_space(line[i]))
	{
		i--;
	}
	line[i] = '\0';
	return (line);
}

int	skip_space(char *line)
{
	int	i;

	i = 0;
	if (!line)
		return (-1);
	while (line[i] != '\0')
	{
		while (is_space(line[i]))
			i++;
		if (line[i] != '\0')
			return (i);
	}
	return (-1);
}
