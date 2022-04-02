#	include "libft.h"

void	*ft_calloc(size_t number, size_t size)
{
	size_t	res;
	void	*sum;

	res = number * size;
	sum = (void *)malloc(res);
	if (!sum)
		exit(1);
	ft_bzero(sum, res);
	return (sum);
}
