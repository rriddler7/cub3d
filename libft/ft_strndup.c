/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:19:14 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by vitya on 10.05.2021.
//
// Тот же стрдап с выделением и копированием но не больше н символов

#include "libft.h"

char	*ft_strndup(char const *s, size_t n)
{
	char	*str;

	str = (char *) malloc(sizeof(char) * n + 1);
	if (!str)
		return (NULL);
	str = ft_mystrncpy(str, s, n);
	return (str);
}
