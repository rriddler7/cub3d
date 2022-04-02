#	include "libft.h"

static int	ft_str_chr(const char *str, char a)
{
	size_t	i;

	i = 0;
	while (str[i])
	{	
		if (str[i] == a)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;
	size_t	i;

	if (s1 == NULL || set == NULL)
		return (NULL);
	end = ft_strlen(s1);
	start = 0;
	i = 0;
	while (s1[start] && ft_str_chr(set, s1[start]))
		start++;
	while (end > start && ft_str_chr(set, s1[end - 1]))
		end--;
	str = (char *)malloc(end - start + 1);
	if (str == NULL)
		exit(1);
	while (start < end)
	{
		str[i] = s1[start];
		i++;
		start++;
	}
	str[i] = '\0';
	return (str);
}
