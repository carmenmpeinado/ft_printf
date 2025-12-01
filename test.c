#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *str;
	// unsigned long p;

	// p = 140723456532345;
	// int	i;
	// char j = 'A'

	// i = 0;
	// str = "Another one bites the dust";
	str = "NULL";
	// if (str && str[i])
	printf("%p\n", str);
	ft_printf("%p", str);
	return (0);
}
