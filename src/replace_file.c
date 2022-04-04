/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:07:59 by rriddler          #+#    #+#             */
/*   Updated: 2022/04/04 20:08:03 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse_file(t_data *data, int fd_file)
{
	char	*save;
	char	*save_replace;

	save = NULL;
	save_replace = NULL;
	while (get_next_line(fd_file, &save))
	{
		save_replace = data->repfile;
		data->repfile = ft_strjoin(save_replace, save);
		free(save_replace);
		free(save);
		save_replace = data->repfile;
		data->repfile = ft_strjoin(save_replace, "\n");
		free(save_replace);
	}
	save_replace = data->repfile;
	data->repfile = ft_strjoin(save_replace, save);
	free(save_replace);
	free(save);
}
