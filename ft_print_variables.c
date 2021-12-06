/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/06 22:28:13 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	create_hex_str(unsigned long int num, char *str, char param)
{
	int	i;
	int	digit;
	
	i = 11;
	str[12] = 0;
	while (i >= 0)
	{
		digit = num % 16;
		num /= 16;
		if (digit <= 9)
			str[i] = digit + '0';
		else if (param == 'X')
			str[i] = (digit - 10) + 'A';
		else str[i] = (digit - 10) + 'a';
		i--;
	}
}

void    print_hex(va_list args, s_params *s_info, int *prnt_cntr, char param)
{
	int i;
	char str[13];
	unsigned long int	argument;

	i = 0;
	argument = va_arg(args, unsigned long int);
	create_hex_str(argument, str, param);
	if (param != 'p')
	{
		while (str[i] == '0')
		i++;
		if (!str[i])
		{
			write (1, "0", 1);
			*prnt_cntr += 1;
		}
	}
	while (str[i])
	{
		write (1, &str[i], 1);
		*prnt_cntr += 1;
		i++;
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
	write (1, "0x", 2);
	*prnt_cntr += 2;
	print_hex(args, s_info, prnt_cntr, 'p');
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
	print_hex(args, s_info, prnt_cntr, 'x');
}

void    print_X(va_list args, s_params *s_info, int *prnt_cntr)
{
	print_hex(args, s_info, prnt_cntr, 'X');
}

void    print_prcnt(va_list args, s_params *s_info, int *prnt_cntr)
{
	write (1, "%", 1);
	prnt_cntr += 1;	
}
