/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:06:58 by rriddler          #+#    #+#             */
/*   Updated: 2022/04/04 20:07:04 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_map(char *file, t_data *data)
{
	int		fd_file;

	init_data(data);
	if (!verify_extension(file, ".cub"))
		ft_error(data, "ext");
	fd_file = open(file, O_RDONLY, 0644);
	if (fd_file == -1)
		ft_error(data, "open_file");
	if (read(fd_file, file, 1) == -1)
		ft_error(data, "open_file");
	else
	{
		parse_file(data, fd_file);
		close(fd_file);
	}
	handle_data(data);
}
