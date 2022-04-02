#include "get_next_line.h"

int	util_foo(ssize_t ret, char **buf, char **remain, int var)
{
	if (var)
	{
		if (ret == -1)
		{
			free(*buf);
			return (-1);
		}
		return (0);
	}
	free(*buf);
	free(*remain);
	*remain = NULL;
	return (0);
}

int	where_is_c(char *s, char c)
{
	int	count;

	count = 0;
	while (s[count] != c)
		count++;
	return (count);
}

char	*ft_strrrchr(char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return (s);
		s++;
	}
	return (0);
}

int	ft_strdup_till_c(char **s1, char **s2, char c, char **buf)
{
	char	*s1_clone;
	char	*s2_clone;

	*s1 = malloc(sizeof(char) * (where_is_c(*s2, c) + 1));
	if (!*s1)
	{
		free(*buf);
		return (-1);
	}
	s1_clone = *s1;
	s2_clone = *s2;
	while (*s2_clone != c)
		*s1_clone++ = *s2_clone++;
	*s1_clone = '\0';
	return (0);
}

int	ft_gnl_strjoin(char **s1, char **s2)
{
	char	*str;
	char	*str_start;
	char	*s1_clone;
	char	*s2_clone;

	str = malloc(sizeof(char) * (where_is_c(*s1, 0) + where_is_c(*s2, 0) + 1));
	if (!str)
	{
		free(*s1);
		free(*s2);
		return (-1);
	}
	s1_clone = *s1;
	s2_clone = *s2;
	str_start = str;
	while (*s1_clone)
		*str++ = *s1_clone++;
	while (*s2_clone)
		*str++ = *s2_clone++;
	*str = '\0';
	free (*s1);
	*s1 = str_start;
	return (0);
}
