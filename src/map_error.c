/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:06:42 by rriddler          #+#    #+#             */
/*   Updated: 2022/04/04 20:06:45 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	verify_first_last_string(int j, t_data *data)

{
	int	i;

	i = 0;
	while (data->map[j][i])
	{
		if (data->map[j][i] != '1' && verify_spt(data->map[j][i], 1))
			ft_error(data, "open_map");
		i++;
	}
}

void	verify_map(t_data *data, int j, int i)
{
	while (data->map[j][i])
	{
		if (data->map[j][i] && data->map[j][i] != '0'
			&& data->map[j][i] != '1' && verify_spt(data->map[j][i], 1)
			&& !verify_plr(data->map[j][i]))
			ft_error(data, "incorr");
		if (data->map[j][i] == '0')
		{
			if ((data->map[j - 1] && ft_strlen(data->map[j - 1]) < i)
				|| (data->map[j - 1][i] && verify_spt(data->map[j - 1][i], 0)))
				ft_error(data, "open_map");
			if ((data->map[j + 1] && ft_strlen(data->map[j + 1]) < i)
				|| (data->map[j + 1][i] && verify_spt(data->map[j + 1][i], 0)))
				ft_error(data, "open_map");
		}
		if (data->map[j][i] && verify_plr(data->map[j][i]) && !data->plr_ch)
			data->plr_ch = data->map[j][i];
		else if (data->map[j][i] && verify_plr(data->map[j][i]) && data->plr_ch)
			ft_error(data, "player_mul");
		i++;
		if ((verify_spt(data->map[j][i], 0) || data->map[j][i] == '\n'
			|| data->map[j][i] == '\0') && (data->map[j][i - 1] != '1'
			&& verify_spt(data->map[j][i - 1], 1)))
			ft_error(data, "open_map");
	}
}

void	map_error(t_data *data)
{
	int	i;
	int	j;

	j = 1;
	verify_first_last_string(0, data);
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] && verify_spt(data->map[j][i], 0))
			i++;
		if (i == 0 && data->map[j][i] == '\0')
			ft_error(data, "wo_no");
		if (data->map[j][i] && data->map[j][i] != '1')
			ft_error(data, "open_map");
		verify_map(data, j, i);
		j++;
		if (!data->map[j + 1])
		{
			verify_first_last_string(j, data);
			break ;
		}
	}
	if (!data->plr_ch)
		ft_error(data, "player");
}
