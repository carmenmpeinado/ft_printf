/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: capeinad <capeinad@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 01:09:02 by capeinad          #+#    #+#             */
/*   Updated: 2025/12/05 12:07:19 by capeinad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	{
		write(1, "0x", 2);
		i = 2;
	}
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
			i = ft_unsint(nbr / 10);
	}
	i += ft_putchar((nbr % 10) + '0');
	return (i);
}

static int	check_format(char const *format, va_list arg, int i)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	if (format[i] == '%')
		count += write(1, "%%", 1);
	else if (format[i] == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (format[i] == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (format[i] == 'p')
		count += ft_putptr(va_arg(arg, void *), flag);
	else if (format[i] == 'd' || format[i] == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (format[i] == 'u')
		count += ft_unsint(va_arg(arg, unsigned int));
	else if (format[i] == 'X' || format[i] == 'x')
		count += ft_puthex(va_arg(arg, unsigned int), format[i]);
	return (count);
}

int	ft_printf(char const *format, ...)
{
	int		count;
	va_list	arg;
	int		i;

	i = 0;
	count = 0;
	va_start(arg, format);
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			count += check_format(format, arg, i);
		}
		else
			count += ft_putchar(format[i]);
		i++;
	}
	va_end(arg);
	return (count);
}
