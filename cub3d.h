# ifndef CUB3D_H
# define CUB3D_H
#include "minilibx-linux/mlx.h"
#include "libft/libft.h"
# include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define SIZE 124
#define PI 3.14159265358979323846
#define TILE_SIZE 32

/*
	virtual map struct, to save the map and recall it when needed
		void	*img: canvas on which to draw a map
		void	*v_map: virtual map
		int		bpp: bit per pixel, usually 32 or 64 depending on system, filled by the mlx_func
		int		line_len: bytes count in row, (~> width*4) depending on system
		int		endean: endean type, little (0) or big (1)
*/
typedef struct s_virtual
{
	void	*img;
	void	*v_map;
	int		bpp;
	int		line_len;
	int		endean;
}		t_virtual;
/*
Map struct, has coordinates for the map, and visuals inside it
as well as color numbers to make a full code
*/
typedef struct s_map
{
	char	**arr_map;
	char	*img_NO;
	char	*img_SO;
	char	*img_WE;
	char	*img_EA;
	int		floor_red;
	int		floor_blue;
	int		floor_green;
	int		ceiling_red;
	int		ceiling_blue;
	int		ceiling_green;
}		t_map;

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
	void	*img;
}	t_player;

typedef struct s_screen
{
	int		height;
	int		width;
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

typedef struct s_data{
	void		*mlx;
	void		*win;
	int			is_mouse_down;
	int			font_size;
	float		*flagx;
	float		*flagy;
	t_algo		*algo;
	t_screen	*screen;
	t_map		*map;
	t_player	*player;
	t_virtual	*virtual;
}	t_data;

void	allocate_structs(t_data *data);
void	mlx_setup(t_data *data);
void	algo_param(t_data *data);
void	setup_algo(t_data *data, int length);

//player
void	setup_position(t_data *data);
void	rotate_player(t_player *p, double angle);
void	custom_putpixel(t_data *data);

//movement
int	x_axis(int key, t_data *data);
int	y_axis(int key, t_data *data);

# endif
