/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amashhad <amashhad@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 16:35:38 by amashhad          #+#    #+#             */
/*   Updated: 2025/07/22 18:43:43 by amashhad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	exit_fnc(void *param)
{
	(void) param;
	exit(0);
	return (0);
}

void	mouse_tracker(void *mlx, void *window, int x, int y)
{
	mlx_mouse_get_pos(mlx, window, &x, &y);
	printf("x: %dy: %d\n", x, y);
}

int	mouse_exit_button(int button, int x, int y, void *param)
{
	t_coord *coord = (t_coord *)param;

	if (button == 1 && coord && (x >= coord->start_x &&
			x <= coord->end_x) && (y >= coord->start_y
				&& y <= coord->end_y))
		exit(0);
	return (0);
}

void	start_window(void *mlx, void *window)
{
	int		img_width = 42;
	int		img_height = 42;
	void	*img;
	img = mlx_xpm_file_to_image(mlx, "assets/test_start.xpm", &img_width, &img_height);
	mlx_put_image_to_window(mlx, window, img, img_width, img_height);
}

int	loop_kill(void *param)
{
	(void)param;
	exit(0);
	return 0;
}
int	main(void)
{
	t_data	*data = malloc(sizeof(t_data));
	if (!data)
		return (1);
	memset(data, 0, sizeof(t_data));

	// Initialize coordinate structure for exit button area
	t_coord *exit_coords = malloc(sizeof(t_coord));
	if (!exit_coords)
	{
		free(data);
		return (1);
	}
	// Set exit button area (adjust these values as needed)
	exit_coords->start_x = 42;
	exit_coords->start_y = 42;
	exit_coords->end_x = 84;
	exit_coords->end_y = 84;

	data->mlx = mlx_init();
	if (!data->mlx)
	{
		free(exit_coords);
		free(data);
		return (1);
	}
	data->window = mlx_new_window(data->mlx, 1280, 720, "Zanqa Game");
	if (!data->window)
	{
		free(exit_coords);
		free(data);
		return (1);
	}
	start_window(data->mlx, data->window);
	//mlx_loop_hook(data->mlx, loop_kill, data);
	mlx_mouse_hook(data->window, mouse_exit_button, exit_coords);
	mlx_loop(data->mlx);
	return (0);
}
