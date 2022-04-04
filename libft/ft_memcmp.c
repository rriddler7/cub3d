/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:01:57 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:01:59 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		if (((unsigned char *)a)[i] != ((unsigned char *)b)[i])
		{
			return (((unsigned char *)a)[i] - ((unsigned char *)b)[i]);
		}
		i++;
	}
	return (0);
}
