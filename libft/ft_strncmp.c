#	include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t lenght)
{
	size_t	i;

	i = 0;
	while (str1[i] && str2[i] && i < lenght)
	{
		if (str1[i] != str2[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
		i++;
	}
	if (i < lenght)
	{
		if (str1[i] != str2[i])
			return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
	}
	return (0);
}
