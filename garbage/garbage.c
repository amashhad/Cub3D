//draws a single line, maxes at length size
// void	draw_line(t_data *data)
// {
// 	int	x = (data->player->player_x);
// 	int y = (data->player->player_y);
// 	int i = 0;
// 	int length = 100;
//     while (i < length)
// 	{
// 		if (x == 0 || y == 0 || data->map->arr_map[y/64][x/64] == '1')
// 			return ;
//         mlx_pixel_put(data->mlx, data->screen->screen, x, y, 0xFF);
//         x += data->player->dir_x * 5;
//         y += data->player->dir_y * 5;
//         i++;
//     }
// }

//draws in 3D form, doesn't work
// void	extra_line(t_data *data, int hit_x, int hit_y, double ray_angle, int ray_index, int rays_total)
// {
//     // 1) Distance from player to hit point
//     double dx = hit_x - data->player->player_x;
//     double dy = hit_y - data->player->player_y;
//     double distance = sqrt(dx*dx + dy*dy);

//     // 2) Fix "fish-eye" effect by projecting straight
//     double corrected_dist = distance * cos(ray_angle - atan2(data->player->dir_y, data->player->dir_x));

//     // 3) Projected wall height on screen
//     int proj_height = (int)((TILE_SIZE * data->screen->height) / corrected_dist);

//     // 4) Column X position on 3D screen
//     double col_width = (double)data->screen->width / (double)rays_total;
//     int col_x = (int)(ray_index * col_width);

//     // 5) Vertical limits (center wall)
//     int start = (data->screen->height / 2) - (proj_height / 2);
//     int end   = (data->screen->height / 2) + (proj_height / 2);

//     if (start < 0) start = 0;
//     if (end >= data->screen->height) end = data->screen->height - 1;

//     // 6) Draw vertical line = one "slice" of wall
//     for (int y = start; y < end; y++)
//     {
//         mlx_pixel_put(data->mlx, data->screen->screen_thrd, col_x, y, 0xFFFFFF);
//     }
// }
