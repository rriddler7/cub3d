#include "cub3d.h"

void	turn_mouse_left(t_data *data, double x)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(x) - \
		data->player.dir_y * sin(x);
	data->player.dir_y = old_dir_x * sin(x) + data->player.dir_y * cos(x);
	data->player.plane_x = data->player.plane_x * cos(x) - \
		data->player.plane_y * sin(x);
	data->player.plane_y = old_plane_x * sin(x) + \
		data->player.plane_y * cos(x);
}

void	turn_mouse_right(t_data *data, double x)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-x) - \
		data->player.dir_y * sin(-x);
	data->player.dir_y = old_dir_x * sin(-x) + data->player.dir_y * cos(-x);
	data->player.plane_x = data->player.plane_x * cos(-x) - \
		data->player.plane_y * sin(-x);
	data->player.plane_y = old_plane_x * sin(-x) + \
		data->player.plane_y * cos(-x);
}

int	mousehook(int x, int y, t_data *data)
{
	if (data->mlx.is_mouse_active == -1 || data->mlx.prev_x_mouse == -1 \
		|| x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
	{
		data->mlx.prev_x_mouse = x;
		data->mlx.prev_y_mouse = y;
		return (0);
	}
	if (x < data->mlx.prev_x_mouse)
		turn_mouse_left(data, (double)(data->mlx.prev_x_mouse - x) / 300.0);
	else if (x > data->mlx.prev_x_mouse)
		turn_mouse_right(data, (double)(x - data->mlx.prev_x_mouse) / 300.0);
	if (y < data->mlx.prev_y_mouse)
		if (data->mlx.prev_y_mouse - y + data->mlx.view_height < HEIGHT / 10)
			data->mlx.view_height += data->mlx.prev_y_mouse - y;
	if (y > data->mlx.prev_y_mouse)
		if (y - data->mlx.prev_y_mouse + data->mlx.view_height > -(HEIGHT / 10))
			data->mlx.view_height -= y - data->mlx.prev_y_mouse;
	data->mlx.prev_x_mouse = x;
	data->mlx.prev_y_mouse = y;
	return (0);
}

int	small_mousehook(int button, int x, int y, t_data *data)
{
	if (x < 0 || x > WIDTH || y < 0 || y > HEIGHT)
		return (0);
	if (button == 1 || button == 2)
		data->mlx.is_mouse_active *= -1;
	return (0);
}
