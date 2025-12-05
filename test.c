#include "ft_printf.h"
#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	// unsigned int str = -333;
	int j = 100;
	int y = 12387912;
	void *x = NULL;
	int prueba;
	int prueba2;
	// unsigned long p = 6484346484348464;
	char g = 'K';
	char *string = "Hello";
	char *nostr= NULL; 
	// unsigned long p;

	// p = 140723456532345;
	// int	i;
	// char j = 'A'

	// i = 0;
	// str = "Another one bites the dust";
	// str = "NULL";
	// if (str && str[i])
	prueba = ft_printf("%s, %i, %d, %s, %x, %X, %c, %p, \n", nostr, j, j, string, y, y, g, x);
	prueba2 = printf("%s, %i, %d, %s, %x, %X, %c, %p, \n", nostr, j, j, string, y, y, g, x);
	printf("%d\n%d", prueba, prueba2);
	return (0);
}
