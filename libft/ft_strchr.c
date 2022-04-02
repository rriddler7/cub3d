#	include "libft.h"

char	*ft_strchr(const char *str, int a)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != (char)a)
		i++;
	if (str[i] == (char)a)
	{
		return ((char *)str + i);
	}
	return (NULL);
}
