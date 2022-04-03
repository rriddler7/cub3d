/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:57:49 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 19:57:51 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	res;
	void	*sum;

	res = number * size;
	sum = (void *)malloc(res);
	if (!sum)
		exit(1);
	ft_bzero(sum, res);
	return (sum);
}
