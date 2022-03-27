#include "cub3d.h"

bool	check_fl_cel_error(char a)
{
	return (a != ' ' && a != '\t' && !(a >= '0' && a <= '9')
		&& a != ',' && a != '\n');
}

bool	check_plr(char a)
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}

bool	check_s_t(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

bool	check_extension(char *str, int check)
{
	int	i;

	i = ft_strlen(str) - 1;
	if (!check && str[i] == 'b' && str[i - 1] == 'u' && str[i - 2] == 'c'
		&& str[i - 3] == '.' && i - 3 != 0 && str[i - 4] != '/')
		return (true);
	if (check && str[i] == 'm' && str[i - 1] == 'p' && str[i - 2] == 'x'
		&& str[i - 3] == '.' && i - 3 != 0 && str[i - 4] != '/')
		return (true);
	return (false);
}
