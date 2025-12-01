#include "ft_printf.h"
#include <stdarg.h>

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
	// else if (format[i] == 'p')
	// 	i = ft_putptr(va_arg(arg, unsigned long));
	// else if (format[i] == 'd' || format[i] == 'i')
	// 	i = ft_putnbr(va_arg(arg, int));
	// else if (format[i] == 'u')
	// 	i = ft_putstr(va_arg(arg, unsigned int));
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

