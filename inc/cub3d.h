#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include "../libft/libft.h"
# include "get_next_line.h"
# include <limits.h>
# include "mlx.h"
# include <math.h>

# define HEIGHT 1080
# define WIDTH 1920
# define ESC 53
# define W 13
# define A 0
# define S 1
# define D 2
# define UP 126
# define LEFT 123
# define DOWN 125
# define RIGHT 124

# define SPEED 0.06
# define ROT_SPEED 0.03

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_img;

typedef struct s_player
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	ray_dir_x;
	double	ray_dir_y;
	int		side;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	double	side_dest_x;
	double	side_dest_y;
	double	delta_dest_x;
	double	delta_dest_y;
	double	wall_dist;
	int		wall_height;
	double	wall_hit;
	int		draw_start;
	int		wall_start;
	int		draw_end;
	int		wall_end;
	int		hit;
}			t_player;

typedef struct s_tex
{
	struct s_img	picture;
	struct s_img	no;
	struct s_img	ea;
	struct s_img	so;
	struct s_img	we;
}			t_tex;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	int		prev_x_mouse;
	int		prev_y_mouse;
	int		view_height;
	int		is_mouse_active;
}					t_mlx;

typedef struct s_keys
{
	int	forward;
	int	backward;
	int	left;
	int	right;
	int	left_turn;
	int	right_turn;
}		t_keys;

typedef struct s_data
{
	char			plr_ch;
	char			*repfile;
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	int				floor;
	int				ceiling;
	char			**map;
	struct s_mlx	mlx;
	struct s_player	player;
	struct s_tex	tex;
	struct s_keys	keys;
}					t_data;

//----PARSER----
int		main(int argc, char **argv);
void	init_data(t_data *data);
void	reaplace_file(t_data *data, int fd_file);
void	map_parser(char *file, t_data *data);
void	make_hex(t_data *data);
void	handling_data(t_data *data);
int		color_handling(int i, t_data *data, char color);
void	read_map(int i, t_data *data);
void	map_error(t_data *data);

//bool
bool	i_is_zero_color(int i, char a, t_data *data);
bool	i_isnt_zero_color(int i, char a, t_data *data);
bool	i_is_zero_cmp(int i, char *arg, t_data *data);
bool	i_isnt_zero_cmp(int i, char *arg, t_data *data);
bool	check_fl_cel_error(char a);
//cheking player (N,S,W,E)
bool	check_plr(char a);
//checking spaces and tabs
bool	check_s_t(char a, int check);
//checking .cub and .xpm
bool	check_extension(char *str, int check);

//error
void	ft_error(t_data *data, char *error);
//cleaning
void	cleaning(t_data *data);
void	free_array(char **array);
//--------------

//----keys.c----
int		keyhook(int keycode, t_data *data);
int		keyrelease(int keycode, t_data *data);
void	press_keys(t_data *data);
//--------------

//----key_funcs.c----
void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	strafe(t_data *data, int dir);
//-------------------

//----key_funcs2.c----
void	turn_left(t_data *data);
void	turn_right(t_data *data);
void	rotate(t_data *data, int cos_val, int sin_val);
//--------------------

//----mouse.c----
int		mousehook(int x, int y, t_data *data);
int		small_mousehook(int button, int x, int y, t_data *data);
//---------------

//----main.c----
int		ft_exit(t_data *data);
//--------------

//----textures.c----
void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);
void	make_image(t_data *data, t_img *img);
void	get_textures(t_data *data);
//------------------

//----cast_walls.c----
int		cast_walls(t_data *data);
//--------------------

//----cast_walls2.c----
void	find_wall_height(t_data *data);
void	find_where_was_the_hit(t_data *data);
void	put_vertical_line(t_data *data, int i);
//--------------------

//----cast_floor.c----
void	cast_floor(t_data *data);
//--------------------

#endif