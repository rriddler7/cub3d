/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrudge <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 19:59:24 by mrudge            #+#    #+#             */
/*   Updated: 2022/04/04 19:59:26 by mrudge           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*str;

	str = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (str->next != NULL)
			str = str->next;
		str->next = new;
	}
}
