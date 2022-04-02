#	include "libft.h"

char	*ft_strdup(const char *str)
{
	size_t	i;
	size_t	lenght;
	char	*cop;

	i = 0;
	lenght = ft_strlen(str);
	cop = (char *)malloc(sizeof(char) * (lenght + 1));
	if (!cop)
		exit(1);
	while (str[i])
	{
		cop[i] = str[i];
		i++;
	}
	cop[i] = '\0';
	return (cop);
}
