#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#  include <unistd.h>
#  include <stdarg.h>

int	ft_printf(char const *format, ...);
int	ft_strlen(char	*str);
int	ft_putstr(char	*str);
int	ft_putchar(char	c);
int	ft_putnbr(int	n);
int	ft_puthex(unsigned int nbr, char c);

#endif
