#	include "libft.h"

void	*ft_memset(void *a, int b, size_t lenght)
{
	while (lenght > 0)
	{
		lenght--;
		((char *)a)[lenght] = ((char)b);
	}
	return (a);
}
