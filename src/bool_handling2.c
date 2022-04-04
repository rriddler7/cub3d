/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bool_handling2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rriddler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:04:29 by rriddler          #+#    #+#             */
/*   Updated: 2022/04/04 20:04:33 by rriddler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

bool	verify_floor_ceil(char a)
{
	return (a != ' ' && a != '\t' && !(a >= '0' && a <= '9')
		&& a != ',' && a != '\n');
}

bool	verify_plr(char a)
{
	return (a == 'N' || a == 'S' || a == 'W' || a == 'E');
}

bool	verify_spt(char a, int check)
{
	if (check)
		return (a != ' ' && a != '\t');
	return (a == ' ' || a == '\t');
}

bool	verify_extension(char *fileext, char *extens)
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
