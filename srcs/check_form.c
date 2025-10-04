/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_form.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:39:38 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/04 21:42:35 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"
static int  check_form_2(t_map *map, char *line, int *i, int *error)
{
    if (line[*i] == 'S' && line[*i + 1] == 'O' && line[*i + 2] == ' ' && map->int_so == 0 && map->out_border == 0)
    {
		*i = *i + 3;
		while (is_space(line[*i]))
			(*i)++;
        if (line[*i] == '\0')
            return (1);
        map->img_so = ft_strdup(line + *i);
        map->int_so = 1;
        *error = 1;
		map->number_img++;
    }
    if (check_form_2_compl(map, line, &i, &error))
        return (1);
    return (0);
}
static int  check_form_3(t_map *map, char *line, int *i, int *error)
{
    if (line[*i] == 'N' && line[*i + 1] == 'O' && line[*i + 2] == ' ' && map->int_no == 0 && map->out_border == 0)
    {
		*i = *i + 3;
		while (is_space(line[*i]))
			(*i)++;
        if (line[*i] == '\0')
            return (1);
        map->img_no = ft_strdup(line + *i);
        map->int_no = 1;
        *error = 1;
		map->number_img++;
    }
    if (check_form_3_compl(map, line, &i, &error))
        return (1);
    return (0);
}
static int  check_form_4(t_map *map, char *line, int *i, int *error)
{
    char    **log;

    log = NULL;
    if (line[*i] == 'F' && line[*i + 1] == ' ' && map->floor_red == -1 && map->out_border == 0)
    {
        *i = *i + 2;
		while (is_space(line[*i]))
			(*i)++;
        if (line[*i] == '\0')
            return (1);
        log = ft_split(line + *i, ',');
        if (!log)
            return (1);
        if (is_number(log))
		{
			ft_farray(log);
            return (1);
		}
        fill_color_of_floor(map, log);
        *error = 1;
		map->number_img++;
        ft_farray(log);
    }
    return (0);
}
static int  check_form_5(t_map *map, char *line, int *i, int *error)
{
    char    **log;

    log = NULL;
    if (line[*i] == 'C' && line[*i + 1] == ' ' && map->ceiling_red == -1 && map->out_border == 0)
    {
		*i = *i + 2;
		while (is_space(line[*i]))
			(*i)++;
        if (line[*i] == '\0')
            return (1);
        log = ft_split(line + *i, ',');
        if (is_number(log))
		{
			ft_farray(log);
			return (1);
		}
        fill_color_of_ciling(map, log);
        *error = 1;
		map->number_img++;
		ft_farray(log);
    }
    return (0);
}
int check_form(t_map *map, char *line)
{
    int		error;
	int		i;

    error = 0;
	i = 0;
	line = skip_revers(line);
	if(!line)
		return (1);
	while (is_space(line[i]))
		i++;
    if (check_form_2(map, line, &i, &error))
        return (1);
    if (check_form_3(map, line, &i, &error))
        return (1);
    if (check_form_4(map, line, &i, &error))
        return (1);
    if (check_form_5(map, line, &i, &error))
        return (1);
    if (check_form_6(map, line, &error))
        return (1);
    return (0);
}
