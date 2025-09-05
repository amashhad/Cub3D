/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dynamic_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/05 04:00:32 by amashhad          #+#    #+#             */
/*   Updated: 2025/09/05 05:58:25 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	handle_frmt(char f, va_list ap)
{
	if (f == 'f')
		free(va_arg(ap, void *));
	else if (f == 'a')
		ft_farray(va_arg(ap, char **));
	else if (f == 'e')
		exit(va_arg(ap, int));
	else
		ft_terminal(ap, f);
}

int	dynamic_free(const char *frmt, ...)
{
	va_list	ap;
	int		i;

	i = 0;
	if (!frmt)
		return (-1);
	va_start(ap, frmt);
	while (frmt[i])
	{
		if (frmt[i] == '%')
		{
			i++;
			handle_frmt(frmt[i], ap);
		}
		i++;
	}
	va_end(ap);
	return (0);
}
