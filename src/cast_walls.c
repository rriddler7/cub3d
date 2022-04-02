#include "cub3d.h"

static void	find_ray_directions_and_distances(t_data *data, int i)
{
	double	camera;

	camera = 2 * i / (double)WIDTH - 1;
	data->player.ray_dir_x = data->player.dir_x + \
		data->player.plane_x * camera;
	data->player.ray_dir_y = data->player.dir_y + \
		data->player.plane_y * camera;
	data->player.map_x = (int)data->player.x;
	data->player.map_y = (int)data->player.y;
	data->player.delta_dest_x = fabs(1 / data->player.ray_dir_x);
	data->player.delta_dest_y = fabs(1 / data->player.ray_dir_y);
}

static void	find_step_values(t_data *data)
{
	if (data->player.ray_dir_x < 0)
	{
		data->player.step_x = -1;
		data->player.side_dest_x = (data->player.x - \
			(double)data->player.map_x) * data->player.delta_dest_x;
	}
	else
	{
		data->player.step_x = 1;
		data->player.side_dest_x = ((double)data->player.map_x + \
			1.0 - data->player.x) * data->player.delta_dest_x;
	}
	if (data->player.ray_dir_y < 0)
	{
		data->player.step_y = -1;
		data->player.side_dest_y = (data->player.y - \
			(double)data->player.map_y) * data->player.delta_dest_y;
	}
	else
	{
		data->player.step_y = 1;
		data->player.side_dest_y = ((double)data->player.map_y + \
			1.0 - data->player.y) * data->player.delta_dest_y;
	}
}

static void	set_hit_value(t_data *data)
{
	if (data->player.side == 0)
	{
		if ((double)data->player.map_x > data->player.x)
			data->player.hit = 1;
		else
			data->player.hit = 2;
	}
	else
	{
		if ((double)data->player.map_y > data->player.y)
			data->player.hit = 3;
		else
			data->player.hit = 4;
	}
}

static void	find_wall_hit(t_data *data)
{
	data->player.hit = 0;
	while (data->player.hit == 0)
	{
		if (data->player.side_dest_x < data->player.side_dest_y)
		{
			data->player.side_dest_x += data->player.delta_dest_x;
			data->player.map_x += data->player.step_x;
			data->player.side = 0;
		}
		else
		{
			data->player.side_dest_y += data->player.delta_dest_y;
			data->player.map_y += data->player.step_y;
			data->player.side = 1;
		}
		if (data->map[data->player.map_x][data->player.map_y] == '1')
			set_hit_value(data);
	}
}

int	cast_walls(t_data *data)
{
	int	i;

	i = 0;
	while (i < WIDTH)
	{
		find_ray_directions_and_distances(data, i);
		find_step_values(data);
		find_wall_hit(data);
		find_wall_height(data);
		find_where_was_the_hit(data);
		put_vertical_line(data, i);
		i++;
	}
	return (0);
}
