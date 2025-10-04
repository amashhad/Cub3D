/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:01:16 by amashhad          #+#    #+#             */
/*   Updated: 2025/10/04 22:03:12 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	algo_param( t_algo *algo)
{
	// cone parameters
	algo->fov = PI / 6;        // 22.5° to each side = 45° cone
	algo->step = PI / 360;     // 1° step (smaller = smoother cone, but more rays)
}
