#include "cub3d.h"

int	check_size_map(int i, t_data *data)
{
	int	size;
	int	save;

	size = 0;
	save = 1;
	while (i < ft_strlen(data->repfile))
	{
		if (data->repfile[i] == '\n' || i == ft_strlen(data->repfile) - 1)
			++size;
		++i;
	}
	--i;
	while (i >= 0 && (data->repfile[i] == ' ' || data->repfile[i] == '\n'
			|| data->repfile[i] == '\t'))
	{
		--i;
		if (data->repfile[i] == '\n')
			++save;
	}
	return (size - save);
}

int	check_n(int i, t_data *data, char **map_elem)
{
	int	start;

	start = i;
	while (data->repfile[i] && data->repfile[i] != '\n')
		++i;
	*map_elem = ft_substr(data->repfile, start, i - start);
	if (data->repfile[i] == '\n')
		++i;
	return (i);
}

void	make_array_map(int i, t_data *data)
{
	int	save_i;
	int	size;
	int	j;

	j = 0;
	save_i = i;
	size = check_size_map(i, data);
	i = save_i;
	data->map = (char **)malloc(sizeof(char *) * (size + 2));
	while (i > 0 && data->repfile[i - 1] != '\n')
		--i;
	while (j < size + 1)
	{
		i = check_n(i, data, &data->map[j]);
		++j;
	}
	data->map[j] = NULL;
}

void	read_map(int i, t_data *data)
{
	while (data->repfile[i] && (data->repfile[i] == ' '
			|| data->repfile[i] == '\t' || data->repfile[i] == '\n'))
		++i;
	if (data->repfile[i] != '1' && data->repfile[i] != '0')
		ft_error(data, "incorr");
	else
	{
		if (data->repfile[i] == '0')
			ft_error(data, "open_map");
		else
			make_array_map(i, data);
	}
	map_error(data);
}
