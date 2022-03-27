#	include "libft.h"

void	*ft_memcpy(void *a, const void *b, size_t lenght)
{
	if (!a && !b)
		return (0);
	while (lenght > 0)
	{
		lenght--;
		((char *)a)[lenght] = ((char *)b)[lenght];
	}
	return (a);
}
