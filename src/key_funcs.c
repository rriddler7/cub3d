#include "cub3d.h"

void	move_forward(t_data *data)
{
	if (data->map[(int)(data->player.x + data->player.dir_x * \
		(SPEED + 0.1))][(int)(data->player.y)] == '0')
		data->player.x += data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y + \
		data->player.dir_y * (SPEED + 0.1))] == '0')
		data->player.y += data->player.dir_y * SPEED;
}

void	move_backward(t_data *data)
{
	if (data->map[(int)(data->player.x - data->player.dir_x * \
		(SPEED + 0.1))][(int)(data->player.y)] == '0')
		data->player.x -= data->player.dir_x * SPEED;
	if (data->map[(int)(data->player.x)][(int)(data->player.y - \
		data->player.dir_y * (SPEED + 0.1))] == '0')
		data->player.y -= data->player.dir_y * SPEED;
}

void	strafe(t_data *data, int dir)
{
	double	new_pos_y;
	double	new_pos_x;

	new_pos_y = data->player.y + data->player.dir_x * SPEED * dir;
	new_pos_x = data->player.x + data->player.dir_y * SPEED * -dir;
	if ((data->map[(int)data->player.x] \
		[(int)(new_pos_y + 0.1 \
		* ft_sign(new_pos_y - data->player.y))]) == '0')
		data->player.y = new_pos_y;
	if ((data->map[(int)(new_pos_x + 0.1 \
		* ft_sign(new_pos_x - data->player.x))] \
		[(int)data->player.y]) == '0')
		data->player.x = new_pos_x;
}
