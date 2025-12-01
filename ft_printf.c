#include "ft_printf.h"
#include <stdarg.h>

static int	ft_putptr(void *ptr, int flag)
{
	unsigned long	nbr;
	char			*base;
	int				i;

	if (ptr == NULL)
		return (write(1, "(nil)", 5));
	nbr = (unsigned long)ptr;
	base = "0123456789abcdef";
	i = 0;
	if (flag)
		i += write(1, "0x", 2);
	if (nbr >= 16)
		i += ft_putptr((void *)(nbr / 16), 0);
	i += ft_putchar(base[nbr % 16]);
	return (i);
}
static int	ft_unsint(unsigned int nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (nbr > 0)
	{
		if (nbr >= 10)
		i += ft_unsint(nbr / 10);
	}
	i += ft_putchar((nbr % 10) + '0');
	
	return (i);
}
int check_format(char const *format, va_list arg)
{
	int i;

	i = 0;
	if (format[1] == '%')
		i = write(1, "%%", 1);
	else if (format[1] == 's')
		i = ft_putstr(va_arg(arg, char *));
	else if (format[1] == 'c')
		i = ft_putchar(va_arg(arg, unsigned int));
	else if (format[1] == 'p')
		i += ft_putptr(va_arg(arg, void *), 1);
	else if (format[1] == 'd' || format[1] == 'i')
		i = ft_putnbr(va_arg(arg, int));
	else if (format[1] == 'u')
		i = ft_unsint(va_arg(arg, unsigned int));
	else if (format[1] == 'X' || format[1] == 'x')
		i = ft_puthex(va_arg(arg, unsigned int), format[1]);
	return (i);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	arg;

	va_start(arg, format);
	if (*format == '%' && format[1])
		count = check_format(format, arg);
	va_end(arg);
	return (count);
}

