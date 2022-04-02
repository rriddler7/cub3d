#include "cub3d.h"

void	check_first_last_string(int j, t_data *data)
{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && check_s_t(data->map[j][i], 1))
			ft_error(data, "open_map");
		i++;
	}
}

void	check_error(t_data *data, int j, int i)
{
	while (data->map[j][i])
	{
		if (data->map[j][i] && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && check_s_t(data->map[j][i], 1)
			&& !check_plr(data->map[j][i]))
			ft_error(data, "incorr");
		if (data->map[j][i] == '0')
		{
			if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i)
				|| (data->map[j - 1][i] && check_s_t(data->map[j - 1][i], 0)))
				ft_error(data, "open_map");
			if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
				|| (data->map[j + 1][i] && check_s_t(data->map[j + 1][i], 0)))
				ft_error(data, "open_map");
		}
		if (data->map[j][i] && check_plr(data->map[j][i]) && !data->plr_ch)
			data->plr_ch = data->map[j][i];
		else if (data->map[j][i] && check_plr(data->map[j][i]) && data->plr_ch)
			ft_error(data, "player_mul");
		i++;
		if ((check_s_t(data->map[j][i], 0) || data->map[j][i] == '\n'
			|| data->map[j][i] == '\0') && (data->map[j][i - 1] != '1'
			&& check_s_t(data->map[j][i - 1], 1)))
			ft_error(data, "open_map");
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	check_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && check_s_t(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
			ft_error(data, "wo_no");
		if (data->map[j][i] && data->map[j][i] != '1')
			ft_error(data, "open_map");
		check_error(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			check_first_last_string(j, data);
			break ;
		}
	}
	if (!data->plr_ch)
		ft_error(data, "player");
}
