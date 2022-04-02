#	include "libft.h"

void	*ft_memchr(void *a, int c, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		if (((unsigned char *)a)[i] == (unsigned char)c)
		{
			return ((unsigned char *)a + i);
		}
		i++;
	}
	return (NULL);
}
