#include "cub3d.h"

void	parse_map(char *file, t_data *data) //map_parser(char *file, t_data *data)
{
	int		fd_file;

	init_data(data);
	if (!verify_extension(file, ".cub")) // if (!check_extension(file, 0))
		ft_error(data, "ext");
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		ft_error(data, "open_file");
	else
	{
		parse_file(data, fd_file);
		close(fd_file);
	}
	handle_data(data);
}
