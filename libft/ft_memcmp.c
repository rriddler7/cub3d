#	include "libft.h"

int	ft_memcmp(const void *a, const void *b, size_t lenght)
{
	size_t	i;

	i = 0;
	while (i < lenght)
	{
		if (((unsigned char *)a)[i] != ((unsigned char *)b)[i])
		{
			return (((unsigned char *)a)[i] - ((unsigned char *)b)[i]);
		}
		i++;
	}
	return (0);
}
