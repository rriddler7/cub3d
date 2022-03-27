#	include "libft.h"

char	*ft_strrchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (str[i] != 0)
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)a)
			return ((char *)str + i);
		i--;
	}
	return (NULL);
}
