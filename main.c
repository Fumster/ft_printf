#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
//	char str[20] = "<str>";
//	char c = 'A';
//	unsigned int x = 3625526;
	int i = 23406304;
//	unsigned int u = 640564084;
	int ret;
//	int *p = &ret;

	ret = ft_printf(" %p ", 9223372036854775807LL);
	printf("\n");
	i  =     printf(" %p ", 9223372036854775807LL);
//	ret = ft_printf("ptr - %p, x - %x\n", 1, 42);
//	printf("ptr - %p, x - %x\n", 1, 42);
	printf("return is - %d\n", ret);
	printf("return is - %d\n", i);
//	ft_printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);
//	   printf("%%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %%%c%%%s%%%d%%%i%%%u%%%x%%%X%%%% %c%%\n", 'A', "42", 42, 42 ,42 , 42, 42, 'B', "-42", -42, -42 ,-42 ,-42, 42, 'C', "0", 0, 0 ,0 ,0, 42, 0);	
	return (0);
}

/*
 * 
hello 6
string_variable 16
World 6
string_variable 16
*/

