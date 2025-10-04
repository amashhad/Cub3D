/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uitil.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alhamdan <alhamdan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 21:27:49 by alhamdan          #+#    #+#             */
/*   Updated: 2025/10/02 21:54:33 by alhamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	is_space(int c)
{
	if (c == ' ')
		return (1);
	else
		return (0);
}

int	move_space(char *str)
{
	if (!str)
		return (-1);
	int	i;

	i = 0;
	while (is_space(str[i]))
	{
		i++;
	}
	return (i);
}

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		result = (result * 10) + (str[i++] - '0');
	return (result * sign);
}

int	is_digit(char	*str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return (1);
		i++;
	}
	return (0);
}

int	is_number(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (is_digit(str[i]))
			return (1);
		if (ft_atoi(str[i]) < 0 || ft_atoi(str[i]) > 255)
			return (1);
		i++;
	}
    if (i != 3)
    {

        return (1);
    }
	return (0);
}