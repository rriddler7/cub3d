#include "cub3d.h"

int	ft_exit(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	mlx_destroy_image(data->mlx.mlx, data->tex.no.img);
	mlx_destroy_image(data->mlx.mlx, data->tex.so.img);
	mlx_destroy_image(data->mlx.mlx, data->tex.ea.img);
	mlx_destroy_image(data->mlx.mlx, data->tex.we.img);
	mlx_destroy_window (data->mlx.mlx, data->mlx.win);
	exit(0);
}

void	init_coords(t_data *data)
{
	data->player.dir_x = -1;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
	if (data->plr_ch == 'W')
		rotate(data, 0, 1);
	else if (data->plr_ch == 'S')
		rotate(data, -1, 0);
	else if (data->plr_ch == 'E')
		rotate(data, 0, -1);
}

void	init_player_data(t_data *data)
{
	int	i;
	int	j;

	init_coords(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->plr_ch)
			{
				data->player.y = (double)j + 0.5;
				data->player.x = (double)i + 0.5;
				data->map[(int)data->player.x][(int)data->player.y] = '0';
				data->mlx.prev_x_mouse = -1;
				data->mlx.is_mouse_active = -1;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	render_image(t_data *data)
{
	press_keys(data);
	cast_walls(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.win, \
		data->tex.picture.img, 0, 0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
	{
		write(2, "Error: too many/few arguments\n", 30);
		return (1);
	}
	ft_memset(&data, 0, sizeof(t_data));
	map_parser(argv[1], &data);
	init_player_data(&data);
	data.mlx.mlx = mlx_init();
	get_textures(&data);
	make_image(&data, &data.tex.picture);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	mlx_mouse_hook(data.mlx.win, small_mousehook, &data);
	mlx_hook(data.mlx.win, 6, 0, mousehook, &data);
	mlx_hook(data.mlx.win, 2, 0, keyhook, &data);
	mlx_hook(data.mlx.win, 3, 0, keyrelease, &data);
	mlx_hook(data.mlx.win, 17, 0, ft_exit, &data);
	mlx_loop_hook(data.mlx.mlx, render_image, &data);
	mlx_loop(data.mlx.mlx);
	cleaning(&data);
	return (0);
}
