/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:01:46 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:02:06 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_memchr(void *a, int c, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		if (((unsigned char *)a)[i] == (unsigned char)c)
		{
			return ((unsigned char *)a + i);
		}
		i++;
	}
	return (NULL);
}
