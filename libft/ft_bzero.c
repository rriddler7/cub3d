#	include "libft.h"

void	ft_bzero(void *a, size_t lenght)
{
	while (lenght > 0)
	{
		lenght--;
		((char *)a)[lenght] = 0;
	}
}
