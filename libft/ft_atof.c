/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:16:33 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_atof(const char *str)
{
	char	*c;
	double	first_part;
	double	second_part;
	int		len;

	c = (char *)str;
	first_part = (double)ft_atoi(str);
	while (*c && *c != '.')
		c++;
	c++;
	second_part = (double)ft_atoi(c);
	len = ft_strlen(c);
	while (len)
	{
		second_part /= 10;
		len--;
	}
	if (first_part > 0)
		return (first_part + second_part);
	return (first_part - second_part);
}
