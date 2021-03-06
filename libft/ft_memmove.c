/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:02:17 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:02:19 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_memmove(void *a, const void *b, size_t lenght)
{
	int	i;

	if (!a && !b)
		return (NULL);
	if (a > b)
	{
		i = lenght - 1;
		while (i >= 0)
		{
			((char *)a)[i] = ((char *)b)[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < (int)lenght)
		{
			((char *)a)[i] = ((char *)b)[i];
			i++;
		}
	}
	return (a);
}
