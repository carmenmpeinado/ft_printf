#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	// char *str;
	int num = -214748364;
	// int	i;
	// char j = 'A'

	// i = 0;
	// str = "Another one bites the dust";
	// if (str && str[i])
	printf("%i\n", num);
	ft_printf("%i", num);
	return (0);
}
