#include "cub3d.h"

bool	verify_floor_ceil(char a) //check_fl_cel_error проверка потолка и пола
{
	return (a != ' ' && a != '\t' && !(a >= '0' && a <= '9')
		&& a != ',' && a != '\n');
}

bool	verify_side(char a) //check_pltr
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}

bool	verify_tab(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

// bool	check_extension(char *str, int check) //check /.cub, /.xpm verify_extens(char *extens, char *cub)
// {
// 	int	i;

// 	i = ft_strlen(str) - 1;
// 	if (!check && str[i] == 'b' && str[i - 1] == 'u' && str[i - 2] == 'c'
// 		&& str[i - 3] == '.' && i - 3 != 0 && str[i - 4] != '/')
// 		return (true);
// 	if (check && str[i] == 'm' && str[i - 1] == 'p' && str[i - 2] == 'x'
// 		&& str[i - 3] == '.' && i - 3 != 0 && str[i - 4] != '/')
// 		return (true);
// 	return (false);
// }

bool	verify_extension(char *fileext, char *extens) //check_extension
{
	int	fileext_len;
	int	extens_len;

	fileext_len = ft_strlen(fileext);
	extens_len = ft_strlen(extens);
	if (fileext_len <= extens_len)
		return (false);
	fileext += fileext_len - extens_len;
	while (*fileext)
	{
		if (*fileext != *extens)
			return (false);
		fileext++;
		extens++;
	}
	return (true);
}
