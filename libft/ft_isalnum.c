/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 22:17:27 by mrudge            #+#    #+#             */
/*   Updated: 2022/01/27 20:18:17 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Created by Mickey Rudge on 5/1/21.
//
// Макрос, возвращающий кодовый номер числа или символа, если это число или
// символ, если нет, то
// возврвщает 0.

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((ft_isalpha(c) || ft_isdigit(c)) > 0)
		return (c);
	return (0);
}
