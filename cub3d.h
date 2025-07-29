# ifndef CUB3D_H
# define CUB3D_H
#define SCREEN_WIDTH 1200
#define SCREEN_HEIGHT 800
#include "minilibx-linux/mlx.h"
# include <X11/keysym.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
Map struct, has coordinates for the map, and visuals inside it
*/
typedef struct s_map{
	char	**map;
	long	x;
	long	y;
}	t_map;

typedef struct s_screen{
	void	*canva;
	int		width;
	int		height;
}	t_screen;

/*
main struct, has mlx and is parent of all structs
*/
typedef struct s_data{
	void		*mlx;
	void		*window;
	int			is_mouse_down;
	int			font_size;
	t_map		*map;
	t_screen	*screen;
}	t_data;

int	font_resize(int button, t_data *data);
int	mouse_move(int x, int y, t_data *data);
int	mouse_press(int button, int x, int y, t_data *data);
int	mouse_release(int button, int x, int y, t_data *data);
# endif
