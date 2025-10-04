/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_pictures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 00:09:05 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 20:47:04 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	fill_bg(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->mid_add + ((y * data->mid_len) + (x * (data->mid_bpp/8)));
	*(unsigned int	*)dst = color;
}
void	bg_img(t_data *data, int ceiling, int floor)
{
	int	x;
	int	y;

	y = 0;
	while (y < (data->screen->height))
	{
		x = 0;
		while (x < (data->screen->width))
		{
			if (y < data->screen->height/2)
				fill_bg(data, x, y, ceiling);
			else
				fill_bg(data, x, y, floor);
			x++;
		}
		y++;
	}
}
