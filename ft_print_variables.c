/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/06 20:41:48 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_hex(unsigned int num, int prnt_cntr, char param)
{
	int	i;
	int	digit;
	char	str[9];
	
	i = 8;
	str[9] = 0;
	while (i >= 0)
	{
		num %=16;
		digit = num;
		if (digit < 9)
			str[i] = digit + '0';
		else if param = 'X'
			str[i] = (digit - 10) + 'A';
		else str[i] = (digit - 10) + 'a';
		i--;
	}
}


void    print_c(va_list args, s_params *s_info, int *prnt_cntr)
{	
	int	argument;

	argument = va_arg(args, int);
	write (1, &argument, 1);
	*prnt_cntr += 1;
	return ;
}

void    print_s(va_list args, s_params *s_info, int *prnt_cntr)

{
	char	*argument;

	argument = va_arg(args, char *);
	print_to((const char *)argument, prnt_cntr, 0);
	return ;
}

void    print_p(va_list args, s_params *s_info, int *prnt_cntr)

{
	unsigned int	argument;

	argument = va_arg(args, unsigned int);
	print_hex(argument, prnt_cntr, 'p');
	return ;
}

void    print_d(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}

void    print_i(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}
void    print_u(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}

void    print_x(va_list args, s_params *s_info, int *prnt_cntr)
{
	unsigned int	argument;

	argument = va_arg(args, unsigned int);
	print_hex(argument, prnt_cntr, 'x');
	return ;
}

void    print_X(va_list args, s_params *s_info, int *prnt_cntr)
{
	unsigned int	argument;

	argument = va_arg(args, unsigned int);
	print_hex(argument, prnt_cntr, 'X');
	return ;
}

void    print_prcnt(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}
