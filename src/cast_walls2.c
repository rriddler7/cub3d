#include "cub3d.h"

void	find_wall_height(t_data *data)
{
	if (data->player.side == 0)
		data->player.wall_dist = (data->player.side_dest_x - \
		data->player.delta_dest_x);
	else
		data->player.wall_dist = (data->player.side_dest_y - \
		data->player.delta_dest_y);
	data->player.wall_height = (int)(HEIGHT / data->player.wall_dist);
	data->player.draw_start = -data->player.wall_height / 2 + \
		HEIGHT / 2 + data->mlx.view_height;
	data->player.wall_start = data->player.draw_start;
	if (data->player.draw_start < 0)
		data->player.draw_start = 0;
	data->player.draw_end = data->player.wall_height / 2 + \
		HEIGHT / 2 + data->mlx.view_height;
	data->player.wall_end = data->player.draw_end;
	if (data->player.draw_end >= HEIGHT)
		data->player.draw_end = HEIGHT - 1;
}

void	find_where_was_the_hit(t_data *data)
{
	if (data->player.side == 0)
		data->player.wall_hit = data->player.y + \
		data->player.wall_dist * data->player.ray_dir_y;
	else
		data->player.wall_hit = data->player.x + \
		data->player.wall_dist * data->player.ray_dir_x;
	data->player.wall_hit -= floor(data->player.wall_hit);
}

static void	put_line_cycle(t_data *data, t_img *img, int i, int mirror)
{
	int	j;
	int	x;
	int	y;

	j = 0;
	while (j < HEIGHT)
	{
		if (j < data->player.draw_start)
			my_mlx_pixel_put(&data->tex.picture, i, j, data->ceiling);
		else if (j >= data->player.draw_end)
			my_mlx_pixel_put(&data->tex.picture, i, j, data->floor);
		else
		{
			if (mirror)
				x = (int)((double)img->width * (1.0 - data->player.wall_hit));
			else
				x = (int)((double)img->width * data->player.wall_hit);
			y = (int)((double)img->height / (double)(data->player.wall_end - \
				data->player.wall_start) * (j - data->player.wall_start));
			my_mlx_pixel_put(&data->tex.picture, i, j, get_pixel_color(img, \
				x, y));
		}
		j++;
	}
}

void	put_vertical_line(t_data *data, int i)
{
	t_img	*img;
	int		mirror;

	if (data->player.hit == 1 || data->player.hit == 4)
		mirror = 1;
	else
		mirror = 0;
	if (data->player.hit == 1)
		img = &data->tex.no;
	else if (data->player.hit == 2)
		img = &data->tex.so;
	else if (data->player.hit == 3)
		img = &data->tex.we;
	else
		img = &data->tex.ea;
	put_line_cycle(data, img, i, mirror);
}
