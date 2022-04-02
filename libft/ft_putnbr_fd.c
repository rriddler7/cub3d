#	include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	c = '-';
	if (n != -2147483648)
	{
		if (n < 0)
		{	
			write(fd, &c, 1);
			n *= -1;
		}
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd('0' + (n % 10), fd);
	}
	else
		ft_putstr_fd("-2147483648", fd);
}
