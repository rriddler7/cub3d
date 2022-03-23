/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:19:17 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by vitya on 28.04.2021.
//

// функция ищет строку срц в строке дст. Если находит, то возвращает
// указатель на начало совпадения, если не находит, то возвращает нулл.
#include "libft.h"

char	*ft_strnstr(const char *dst, const char *src, size_t n)
{
	size_t	len_2;

	len_2 = ft_strlen(src);
	if (src[0] == '\0')
		return ((char *) dst);
	while (*dst != '\0' && n-- >= len_2)
	{
		if (*dst == *src && ft_memcmp(dst, src, len_2) == 0)
			return ((char *) dst);
		dst++;
	}
	return (NULL);
}
