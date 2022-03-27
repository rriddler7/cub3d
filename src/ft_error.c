#include "cub3d.h"

void	ft_error2(char *error)
{
	if (ft_strncmp(error, "open_map", 8) == 0)
		write(2, "Error\nopen map\n", 15);
	else if (ft_strncmp(error, "player_mul", 10) == 0)
		write(2, "Error\nmultiple players on the map\n", 34);
	else if (ft_strncmp(error, "player", 6) == 0)
		write(2, "Error\nplayer not found\n", 23);
	else if (ft_strncmp(error, "ext", 3) == 0)
		write(2, "Error\nwrong extension\n", 22);
}

void	ft_error(t_data *data, char *error)
{
	cleaning(data);
	if (ft_strncmp(error, "rgb", 3) == 0)
		write(2, "Error\nrgb color must be from 0 to 255\n", 38);
	else if (ft_strncmp(error, "num_rgb", 7) == 0)
		write(2, "Error\nrgb color must consist of 3 numbers\n", 42);
	else if (ft_strncmp(error, "open_file", 9) == 0)
		write(2, "Error\nfile not found or permission denied\n", 42);
	else if (ft_strncmp(error, "incorr", 8) == 0)
		write(2, "Error\nparameters are incorrect\n", 31);
	else if (ft_strncmp(error, "wo_no", 5) == 0)
		write(2, "Error\nempty string without arguments\n", 37);
	else if (ft_strncmp(error, "rep_param", 9) == 0)
		write(2, "Error\nrepeating parameters\n", 27);
	else if (ft_strncmp(error, "wr_order", 8) == 0)
		write(2, "Error\nwrong order (NO, SO, WE, EA, F, C, *map*)\n", 48);
	else if (ft_strncmp(error, "text_error", 8) == 0)
		write(2, "Error\ntextures do not exist or access is denied\n", 48);
	else if (ft_strncmp(error, "color_num", 9) == 0)
		write(2, "Error\nF/C should only contain numbers and a sep ','\n", 52);
	else
		ft_error2(error);
	exit (1);
}
