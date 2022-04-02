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
