#include "cub3d.h"

bool	i_is_zero_color(int i, char a, t_data *data)
{
	return (data->repfile[i] == a && (data->repfile[i + 1] == ' '
			|| data->repfile[i + 1] == '\t' || data->repfile[i + 1] == '\n'));
}

bool	i_isnt_zero_color(int i, char a, t_data *data)
{
	return ((data->repfile[i - 1] == ' ' || data->repfile[i - 1] == '\t'
			|| data->repfile[i - 1] == '\n') && data->repfile[i] == a
		&& (data->repfile[i + 1] == ' ' || data->repfile[i + 1] == '\t'
			|| data->repfile[i + 1] == '\n'));
}

bool	i_is_zero_cmp(int i, char *arg, t_data *data)
{
	return (data->repfile[i] == arg[0] && data->repfile[i + 1] == arg[1]
		&& (data->repfile[i + 2] == ' ' || data->repfile[i + 2] == '\t'
			|| data->repfile[i + 2] == '\n'));
}

bool	i_isnt_zero_cmp(int i, char *arg, t_data *data)
{
	return (data->repfile[i] == arg[0] && data->repfile[i + 1] == arg[1]
		&& (data->repfile[i - 1] == ' ' || data->repfile[i - 1] == '\t'
			|| data->repfile[i - 1] == '\n') && (data->repfile[i + 2] == ' '
			|| data->repfile[i + 2] == '\t' || data->repfile[i + 2] == '\n'));
}
