#	include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t lenght)
{
	size_t	len_d;
	size_t	len_s;
	size_t	i;
	size_t	j;

	len_d = ft_strlen(dst);
	len_s = ft_strlen(src);
	i = len_d;
	j = 0;
	if (lenght < len_d)
		return (lenght + len_s);
	if (lenght > 0)
	{
		while (src[j] && (len_d + j) < lenght - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (len_d + len_s);
}
