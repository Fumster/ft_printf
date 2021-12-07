#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	char str[20] = "<str>";
	char c = 'A';
	unsigned int x = 3625526;
	int i = 23406304;
	unsigned int u = 640564084;
	int ret;
	int *p = &ret;

	ret = ft_printf("%%%%%%%%%%%%hello %s World %c ptr - %p, x - %x, u - %u, d - %d \n", str, c, p, 42, u, i);
	printf("return is - %d", ret);
	printf("     p is - %p, x - %x, u - %u, d - %d\n\n\n\n", p, 42, u, i);
	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);	
	   printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);	
	return (0);
}

/*
 * 
hello 6
string_variable 16
World 6
string_variable 16
*/

