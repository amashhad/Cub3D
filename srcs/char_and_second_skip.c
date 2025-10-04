/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_and_second_skip.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:37:04 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 04:14:56 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
int	char_valid_player(t_map *map, char c)
{
	if (c == 'N')
	{
		map->player++;
		return (1);
	}
	if (c == 'S')
	{
		map->player++;
		return (1);
	}
	if (c == 'W')
	{
		map->player++;
		return (1);
	}
	if (c == 'E')
	{
		map->player++;
		return (1);
	}
	return (0);
}
int	char_valid(t_map *map, char c)
{
	if (c == '1')
		return (1);
	if (c == '0')
		return (1);
	if (c == ' ')
		return (1);
	if (char_valid_player(map, c))
		return (1);
	return (0);
}
int	check_char(t_map *map, char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (!char_valid(map, str[i]))
			return (0);
		i++;
	}
	return (1);
}
int	skip_space_front(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	return (i);
}
int	skip_space_bake(char *str)
{
	size_t	i;

	i = ft_strlen(str) - 1;
	while (is_space(str[i]))
	{
		i--;
	}
	return (i);
}
