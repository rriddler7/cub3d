#include "get_next_line.h"

int	first_check(int fd, char **line, char **buf, ssize_t *ret)
{
	if (fd < 0 || !line || BUFFER_SIZE < 1)
		return (-1);
	*buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*buf)
		return (-1);
	*ret = 1;
	return (0);
}

int	first_call(char **remain, char **buf)
{
	char	*buf_clone;
	char	*remain_clone;

	if (!*remain)
	{
		*remain = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!(*remain))
		{
			free(*buf);
			return (-1);
		}
		buf_clone = *buf;
		remain_clone = *remain;
		while (*buf_clone)
			*remain_clone++ = *buf_clone++;
		*remain_clone = '\0';
	}
	return (0);
}

int	if_there_is_n_in_remain(char **remain, char **line, char **buf)
{
	char	*temp;
	char	*temp_for_n;

	temp_for_n = ft_strrrchr(*remain, '\n') + 1;
	if (ft_strdup_till_c(line, remain, '\n', buf))
	{
		free (*remain);
		return (-1);
	}
	if (ft_strdup_till_c(&temp, &temp_for_n, '\0', buf))
	{
		free(*remain);
		return (-1);
	}
	free(*remain);
	*remain = temp;
	return (0);
}

int	foo_for_return(char **remain, char **line, ssize_t ret, char **buf)
{
	if (ft_strrrchr(*remain, '\n'))
	{
		if (if_there_is_n_in_remain(remain, line, buf))
			return (-1);
	}
	else if (ret == 0)
	{
		if (ft_strdup_till_c(line, remain, '\0', buf))
		{
			free(*remain);
			return (-1);
		}
		return (util_foo(ret, buf, remain, 0));
	}
	free(*buf);
	return (1);
}

int	get_next_line(int fd, char **line)
{
	ssize_t		ret;
	char		*buf;
	static char	*remain;

	if (first_check(fd, line, &buf, &ret))
		return (-1);
	while (ret > 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (util_foo(ret, &buf, &remain, 1))
			return (-1);
		buf[ret] = '\0';
		if (!remain)
		{
			if (first_call(&remain, &buf))
				return (-1);
		}
		else if (ft_gnl_strjoin(&remain, &buf))
			return (-1);
		if (ft_strrrchr(remain, '\n'))
			break ;
	}
	return (foo_for_return(&remain, line, ret, &buf));
}

/*
// int	main()
// {
// 	char	*line;
// 	int		ret;
// 	int		fd = open("test.txt", O_RDONLY);
// 	while (1)
// 	{
// 		ret = get_next_line(fd, &line);
// 		printf("%d %s\n", ret, line);
// 		free(line);
// 		if (ret == -1)
// 			return (-1);
// 		if (ret == 0)
// 			return (0);
// 	}
// 	return (0);
// }
*/