#include "cub3d.h"

void	turn_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(ROT_SPEED) - \
		data->player.dir_y * sin(ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(ROT_SPEED) + \
		data->player.dir_y * cos(ROT_SPEED);
	data->player.plane_x = data->player.plane_x * cos(ROT_SPEED) - \
		data->player.plane_y * sin(ROT_SPEED);
	data->player.plane_y = old_plane_x * sin(ROT_SPEED) + \
		data->player.plane_y * cos(ROT_SPEED);
}

void	turn_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos(-ROT_SPEED) \
		- data->player.dir_y * sin(-ROT_SPEED);
	data->player.dir_y = old_dir_x * sin(-ROT_SPEED) + \
		data->player.dir_y * cos(-ROT_SPEED);
	data->player.plane_x = data->player.plane_x * cos(-ROT_SPEED) - \
		data->player.plane_y * sin(-ROT_SPEED);
	data->player.plane_y = old_plane_x * sin(-ROT_SPEED) + \
		data->player.plane_y * cos(-ROT_SPEED);
}

void	rotate(t_data *data, int cos_val, int sin_val)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->player.dir_x;
	old_plane_x = data->player.plane_x;
	data->player.dir_x = data->player.dir_x * cos_val - \
		data->player.dir_y * sin_val;
	data->player.dir_y = old_dir_x * sin_val + \
		data->player.dir_y * cos_val;
	data->player.plane_x = data->player.plane_x * cos_val - \
		data->player.plane_y * sin_val;
	data->player.plane_y = old_plane_x * sin_val + \
		data->player.plane_y * cos_val;
}
