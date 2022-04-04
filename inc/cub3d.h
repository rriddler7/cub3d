/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:53:17 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:53:19 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	int		view_height;
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
void	parse_file(t_data *data, int fd_file);
void	parse_map(char *file, t_data *data);

void	handle_data(t_data *data);
int		floor_ceil_color(int i, t_data *data, char color);
void	read_map(int i, t_data *data);
void	map_error(t_data *data);

//bool
bool	i_is_zero_color(int i, char a, t_data *data);
bool	i_isnt_zero_color(int i, char a, t_data *data);
bool	i_is_zero_cmp(int i, char *arg, t_data *data);
bool	i_isnt_zero_cmp(int i, char *arg, t_data *data);
bool	verify_floor_ceil(char a);
bool	verify_plr(char a);
bool	verify_spt(char a, int check);
bool	verify_extension(char *fileext, char *extens);

//error
void	ft_error(t_data *data, char *error);
//cleaning
void	clean(t_data *data);
void	free_array(char **array);

int		keyhook(int keycode, t_data *data);
int		keyrelease(int keycode, t_data *data);
void	press_keys(t_data *data);

void	move_forward(t_data *data);
void	move_backward(t_data *data);
void	strafe(t_data *data, int dir);

void	turn_left(t_data *data);
void	turn_right(t_data *data);
void	rotate(t_data *data, int cos_val, int sin_val);

int		ft_exit(t_data *data);

void	my_mlx_pixel_put(t_img *img, int x, int y, int color);
int		get_pixel_color(t_img *img, int x, int y);
void	make_image(t_data *data, t_img *img);
void	make_textures(t_data *data);

int		cast_walls(t_data *data);
//--------------------

//----cast_walls2.c----
void	find_wall(t_data *data);
void	find_where_was_the_hit(t_data *data);
void	put_vertical_line(t_data *data, int i);
//--------------------

//----cast_floor.c----
void	cast_floor(t_data *data);
//--------------------

#endif
