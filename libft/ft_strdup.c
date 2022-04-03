/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 20:05:55 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 20:05:57 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	lenght;
	char	*cop;

	i = 0;
	lenght = ft_strlen(str);
	cop = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!cop)
		exit(1);
	while (str[i])
	{
		cop[i] = str[i];
		i++;
	}
	cop[i] = '\0';
	return (cop);
}
