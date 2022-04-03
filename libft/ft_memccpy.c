/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:05:12 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:05:15 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_memccpy(void *a, const void *b, int c, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		((unsigned char *)a)[i] = ((unsigned char *)b)[i];
		if (((unsigned char *)b)[i] == (unsigned char)c)
			return ((unsigned char *)a + i + 1);
		i++;
	}
	return (NULL);
}
