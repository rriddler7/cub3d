#	include "libft.h"

char	*ft_substr(char const *s, unsigned int start, int len)
{
	char	*str;
	int		j;
	int		i;

	j = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (ft_strlen(s) < len)
		str = (char *)malloc(ft_strlen(s) + 1);
	else
		str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		exit(1);
	while (s[i] != '\0')
	{
		if (i >= (int)start && j < len)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}
