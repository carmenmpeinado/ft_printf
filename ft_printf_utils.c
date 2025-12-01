#include "ft_printf.h"
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str)
		i++;
	return (i);
}
int	ft_puthex(unsigned int nbr, char c)
{
	char *base;
	int	i;

	if (c == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	i = 0;
	if (nbr >= 16)
		i += ft_puthex((nbr / 16), c);
	i += write(1, &base[nbr % 16], 1);
	return (i);
}
int	ft_putchar(char c)
{
	int i;

	i = 0;
	if (c)
		i = write(1, &c, 1);
	return (i);
}
int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}
int	ft_putnbr(int n)
{
	int	i;
	char	digit;

	i = 0;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
		i += ft_putnbr(n / 10);
	digit = (n % 10 + '0');
	i += write(1, &digit, 1);
	return (i);
}
