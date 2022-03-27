#	include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;
	int		len_s;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	str = (char *)malloc(len_s + 1);
	if (str == NULL)
		exit(1);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
