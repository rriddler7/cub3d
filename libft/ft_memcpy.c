/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:01:36 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:01:38 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_memcpy(void *a, const void *b, size_t lenght)
{
	if (!a && !b)
		return (0);
	while (lenght > 0)
	{
		lenght--;
		((char *)a)[lenght] = ((char *)b)[lenght];
	}
	return (a);
}
