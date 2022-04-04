/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:05:56 by rriddler          #+#    #+#             */
/*   Updated: 2022/04/04 20:05:59 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cut_data(int i, t_data *data, char **str)
{
	int	start;

	start = 0;
	if (*str)
		ft_error(data, "rep_param");
	while (data->repfile[i] && (data->repfile[i] == ' '
			|| data->repfile[i] == '\t'))
		i++;
	start = i;
	while (data->repfile[i] && data->repfile[i] != ' '
		&& data->repfile[i] != '\t' && data->repfile[i] != '\n')
		i++;
	if (start == i)
		ft_error(data, "wo_no");
	*str = ft_substr(data->repfile, start, i - start);
	if (data->repfile[i] != '\n')
	{
		while (data->repfile[i] && data->repfile[i] != '\n'
			&& (data->repfile[i] == ' ' || data->repfile[i] == '\t'))
			i++;
		if (data->repfile[i] != '\n')
			ft_error(data, "incorr");
	}
	return (i);
}

void	verify_textures(t_data *data)
{
	if (access(data->no, R_OK) || access(data->so, R_OK)
		|| access(data->we, R_OK) || access(data->ea, R_OK))
		ft_error(data, "text_error");
	if (!verify_extension(data->no, ".xpm")
		|| !verify_extension(data->no, ".xpm")
		|| !verify_extension(data->we, ".xpm")
		|| !verify_extension(data->ea, ".xpm"))
		ft_error(data, "ext");
}

int	selecte_param(int i, t_data *data)
{
	if (i == 0 && i_is_zero_cmp(i, "NO", data))
		i = cut_data(i + 2, data, &data->no);
	else if (i > 0 && i_isnt_zero_cmp(i, "NO", data))
		i = cut_data(i + 2, data, &data->no);
	else if (i == 0 && i_is_zero_cmp(i, "SO", data))
		i = cut_data(i + 2, data, &data->so);
	else if (i > 0 && i_isnt_zero_cmp(i, "SO", data))
		i = cut_data(i + 2, data, &data->so);
	else if (i == 0 && i_is_zero_cmp(i, "WE", data))
		i = cut_data(i + 2, data, &data->we);
	else if (i > 0 && i_isnt_zero_cmp(i, "WE", data))
		i = cut_data(i + 2, data, &data->we);
	else if (i == 0 && i_is_zero_cmp(i, "EA", data))
		i = cut_data(i + 2, data, &data->ea);
	else if (i > 0 && i_isnt_zero_cmp(i, "EA", data))
		i = cut_data(i + 2, data, &data->ea);
	else if (i == 0 && i_is_zero_color(i, 'F', data))
		i = floor_ceil_color(i + 1, data, 'F');
	else if (i > 0 && i_isnt_zero_color(i, 'F', data))
		i = floor_ceil_color(i + 1, data, 'F');
	else if (i == 0 && i_is_zero_color(i, 'C', data))
		i = floor_ceil_color(i + 1, data, 'C');
	else if (i > 0 && i_isnt_zero_color(i, 'C', data))
		i = floor_ceil_color(i + 1, data, 'C');
	return (i);
}

void	handle_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->repfile[i])
	{
		i = selecte_param(i, data);
		if (data->repfile[i] != ' ' && data->repfile[i] != '\t'
			&& data->repfile[i] != '\n')
			ft_error(data, "incorr");
		if (data->no && data->so && data->so && data->ea
			&& data->floor != -1 && data->ceiling != -1)
			break ;
		i++;
	}
	verify_textures(data);
	read_map(i, data);
}
