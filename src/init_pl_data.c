#include "cub3d.h"

void	init_cs(t_data *data)
{
	data->player.dir_x = -1;
	data->player.dir_y = 0;
	data->player.plane_x = 0;
	data->player.plane_y = 0.66;
}

void	init_pl_data(t_data *data)
{
	int	i;
	int	j;

	init_cs(data);
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[j])
		{
			if (data->map[i][j] == data->plr_ch)
			{
				data->player.y = (double)j + 0.5;
				data->player.x = (double)i + 0.5;
				data->map[i][j] = '0';
				return ;
			}
			j++;
		}
		i++;
	}
}
