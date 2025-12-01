#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	char *str;
	// int num = 13904713;
	// int	i;
	// char j = 'A';

	// i = 0;
	str = "Another one bites the dust";
	// if (str && str[i])
	ft_printf("%s", str);
	printf("%s\n", str);
	return (0);
}
