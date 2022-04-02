#include "cub3d.h"

int	to_hex(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	hext_char_to_int(t_data *data, char **array_atoi, char color)
{
	long long	r;
	long long	g;
	long long	b;

	if (!array_atoi[0] || !array_atoi[1] || !array_atoi[2])
		ft_error(data, "incorr");
	r = ft_atoi(array_atoi[0]);
	g = ft_atoi(array_atoi[1]);
	b = ft_atoi(array_atoi[2]);
	if (r > 255 || g > 255 || b > 255)
		ft_error(data, "rgb");
	if (color == 'F')
		data->floor = to_hex(r, g, b);
	else if (color == 'C')
		data->ceiling = to_hex(r, g, b);
}

int	color_handling3(int i, int start, t_data *data, char **array_atoi)
{
	int	j;

	j = 0;
	while (array_atoi[j])
		j++;
	while (data->repfile[i] && data->repfile[i] != ','
		&& data->repfile[i] != '\n')
	{
		if (check_fl_cel_error(data->repfile[i]))
			ft_error(data, "incorr");
		i++;
	}
	if (check_fl_cel_error(data->repfile[i]))
		ft_error(data, "incorr");
	if (i != start)
	{
		if (j == 3)
			ft_error(data, "num_rgb");
		array_atoi[j] = ft_substr(data->repfile, start, i - start);
		j++;
		if (j == 3)
			array_atoi[j] = NULL;
	}
	return (i);
}

int	color_handling2(int i, t_data *data, char **array_atoi, char color)
{
	int	start;

	start = 0;
	while (data->repfile[i] && data->repfile[i] != '\n')
	{
		while (data->repfile[i] && (data->repfile[i] == ' '
				|| data->repfile[i] == '\t') && data->repfile[i] != '\n')
		{
			i++;
			if (data->repfile[i] == ',')
				ft_error(data, "rgb");
		}
		start = i;
		i = color_handling3(i, start, data, array_atoi);
		if (data->repfile[i] == '\n')
		{
			hext_char_to_int(data, array_atoi, color);
			break ;
		}
		i++;
	}
	return (i);
}

int	color_handling(int i, t_data *data, char color)
{
	char	**array_atoi;
	int		j;

	j = 0;
	array_atoi = (char **)malloc(sizeof(char *) * 4);
	while (j < 4)
		array_atoi[j++] = NULL;
	if (!array_atoi)
		exit(1);
	i = color_handling2(i, data, array_atoi, color);
	if (array_atoi)
		free_array(array_atoi);
	return (i);
}
