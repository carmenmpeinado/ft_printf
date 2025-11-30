#include "ft_printf.h"

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
