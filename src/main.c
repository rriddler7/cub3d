#include "cub3d.h"

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
//	printf("%s", data.repfile);
	init_pl_data(&data);
	data.mlx.mlx = mlx_init();
	texture(&data);
	image(&data, &data.tex.picture);
	data.mlx.win = mlx_new_window(data.mlx.mlx, WIDTH, HEIGHT, "Cub3d");
	mlx_loop(data.mlx.mlx);
	cleaning(&data);
	return (0);
}
