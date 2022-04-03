/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:05:46 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:05:47 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)a)
		i++;
	if (str[i] == (char)a)
	{
		return ((char *)str + i);
	}
	return (NULL);
}
