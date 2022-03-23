/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:19:07 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by vitya on 04.05.2021.
//

//Функция итерируется по строке с, производя операции с каждым элементом
// функцией ф, после, выделяя память под новый масиив арр и записывая
// результаты в него
#include "libft.h"

char	*ft_strmapi(char const *c, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*arr;
	size_t			len_c;

	i = 0;
	if (!c || !f)
		return (NULL);
	len_c = ft_strlen(c);
	arr = (char *)malloc(sizeof(char) * (len_c + 1));
	if (!arr)
		return (NULL);
	while (c[i])
	{
		arr[i] = (*f)(i, c[i]);
		i++;
	}
	arr[i] = '\0';
	return (arr);
}
