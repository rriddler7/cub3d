#include "cub3d.h"

int	data_clipping(int i, t_data *data, char **str)
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

void	data_validation(t_data *data)
{
	if (access(data->no, R_OK) || access(data->so, R_OK)
		|| access(data->we, R_OK) || access(data->ea, R_OK))
		ft_error(data, "text_error");
	if (!check_extension(data->no, 1) || !check_extension(data->no, 1)
		|| !check_extension(data->we, 1) || !check_extension(data->ea, 1))
		ft_error(data, "ext");
}

int	param_selection(int i, t_data *data)
{
	if (i == 0 && i_is_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no);
	else if (i > 0 && i_isnt_zero_cmp(i, "NO", data))
		i = data_clipping(i + 2, data, &data->no);
	else if (i == 0 && i_is_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so);
	else if (i > 0 && i_isnt_zero_cmp(i, "SO", data))
		i = data_clipping(i + 2, data, &data->so);
	else if (i == 0 && i_is_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we);
	else if (i > 0 && i_isnt_zero_cmp(i, "WE", data))
		i = data_clipping(i + 2, data, &data->we);
	else if (i == 0 && i_is_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea);
	else if (i > 0 && i_isnt_zero_cmp(i, "EA", data))
		i = data_clipping(i + 2, data, &data->ea);
	else if (i == 0 && i_is_zero_color(i, 'F', data))
		i = color_handling(i + 1, data, 'F');
	else if (i > 0 && i_isnt_zero_color(i, 'F', data))
		i = color_handling(i + 1, data, 'F');
	else if (i == 0 && i_is_zero_color(i, 'C', data))
		i = color_handling(i + 1, data, 'C');
	else if (i > 0 && i_isnt_zero_color(i, 'C', data))
		i = color_handling(i + 1, data, 'C');
	return (i);
}

void	handling_data(t_data *data)
{
	int	i;

	i = 0;
	while (data->repfile[i])
	{
		i = param_selection(i, data);
		if (data->repfile[i] != ' ' && data->repfile[i] != '\t'
			&& data->repfile[i] != '\n')
			ft_error(data, "incorr");
		if (data->no && data->so && data->so && data->ea
			&& data->floor != -1 && data->ceiling != -1)
			break ;
		i++;
	}
	data_validation(data);
	read_map(i, data);
}
