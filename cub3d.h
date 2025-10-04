# ifndef CUB3D_H
# define CUB3D_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include "srcs/map.h"

#define SIZE 124
#define PI 3.14159265358979323846
#define TILE_SIZE 32

typedef struct s_texture
{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endean;
	int		width;
	int		height;
}	t_texture;

typedef struct s_walls
{
	double	px;
	double	py;
	double	angle;
	double	fov;
	double	dist;
	double	ray_angle;
	double	ray_dx;
	double	ray_dy;
	double	delta_x;
	double	delta_y;
	double	side_dist_x;
	double	side_dist_y;
	double	prep_dist;
	double	wall_x;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		start;
	int		end;
	int		src_offset;
	int		dst_offset;
	int		color;
	int		y;
	int		d;
	int		tex_h;
	int		tex_bpp_bytes;
	int		virt_bpp_bytes;
	int		texture_id;
	int		texture_x;
	int		texture_y;
} t_walls;

typedef struct s_virtual
{
	void	*img;
	char	*v_map;
	int		bpp;
	int		line_len;
	int		endean;
}		t_virtual;

/*
Map struct, has coordinates for the map, and visuals inside it
as well as color numbers to make a full code
*/

typedef struct s_mdata
{
	char	**arr_map;
	char	*img_no;
	char	*img_so;
	char	*img_we;
	char	*img_ea;
	int		floor_red;
	int		floor_blue;
	int		floor_green;
	int		floor_color;
	int		ceiling_red;
	int		ceiling_blue;
	int		ceiling_green;
	int		ceiling_color;
	int		map_coln;
	int		map_row;
	char	player_pos;
}		t_mdata;

/*
	player_x, player_y = player (x, y)
	dir_x, dir_y = player_direction, (North:(0, -1)East(1, 0)West(-1, 0)South(0, 1))
	camera_x, camera_y = player_FOV(field of view)
*/

typedef struct s_player
{
	float	player_x;
	float	player_y;
	float	dir_x;
	float	dir_y;
	float	camera_x;
	float	camera_y;
	int		speed;
	void	*img;
}	t_player;

typedef struct s_screen
{
	int		height;
	int		width;
	int		bpp;
	int		len;
	int		endean;
	char	*add;
	void	*screen_thrd;
}	t_screen;

typedef struct	s_algo
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		ray_index;
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		err;
	int		cx;
	int		cy;
	int		tile_size;
	double	angle;
	double	ray_angle;
	double	fov;
	double	step;
}	t_algo;


/*
main struct, has mlx and is parent of all structs
*/
typedef struct s_data
{
	void		*mlx;
	void		*win;
	int			is_mouse_down;
	int			font_size;
	float		*flagx;
	float		*flagy;
	void		*middle;
	char		*mid_add;
	int			mid_bpp;
	int			mid_len;
	int			mid_endean;
	int			mid_h;
	int			mid_w;
	t_walls		*walls;
	t_algo		*algo;
	t_screen	*screen;
	t_mdata		*mdata;
	t_player	*player;
	t_virtual	*virtual;
	t_texture	texture[4];
}	t_data;

void	allocate_structs(t_data *data);
void	mlx_setup(t_data *data);
void	setup_algo(t_data *data, t_algo *algo,  int length);
void	project_walls(t_algo *algo, t_walls *walls, t_data *data);

//player
void	setup_position(t_data *data, t_mdata *map);
void	rotate_player(t_player *player, double angle);
void	custom_putpixel(t_data *data);

//movement
int	x_axis(int key, t_data *data);
int	y_axis(int key, t_data *data);

//map
void	create_map_buffer(t_data *data);

//background
void	bg_img(t_data *data, int ceiling, int floor);
void	mount_middle(t_data *data);
void	draw_vision(t_data *data, t_algo *algo);
int		speed_dial(int key, t_data *data);
void	free_keys(t_data *data);
int		keys(int key, t_data *data);
void	wall_height(t_data *data, t_walls *walls);
void	side_step(t_data *data, t_walls *walls);
void	algo_param( t_algo *algo);

# endif
