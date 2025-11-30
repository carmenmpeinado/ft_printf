#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	// char *str;
	int num = 13904713;
	int	i;

	i = 0;
	// str = "13904713";
	// if (str && str[i])
	if (!ft_printf("%x", num))
		return (1);
	printf("%x\n", num);
	return (0);
}
