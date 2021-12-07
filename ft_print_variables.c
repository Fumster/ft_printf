/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/07 21:19:23 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int num, int *prnt_cntr)
{
	int digit;

	digit = num + 48;
	if (num == 0)
	{
		write (1, "0", 1);
		*prnt_cntr += 1;
	}
	else if (num > 9)
	{
		digit = num % 10 + 48;
		print_unsigned(num / 10, prnt_cntr);
	}
	write(1, &digit, 1);
	*prnt_cntr += 1;
}

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

void    print_hex(unsigned long int num, s_params *s_info, int *prnt_cntr, char param)
{
	int i;
	char str[13];

	i = 0;
	create_hex_str(num, str, param);
	if (param != 'p' || num == 0)
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
	unsigned long int	argument;
	
	argument = va_arg(args, unsigned long int);
	write (1, "0x", 2);
	*prnt_cntr += 2;
	print_hex(argument, s_info, prnt_cntr, 'p');
	return ;
}

void    print_int(va_list args, s_params *s_info, int *prnt_cntr)
{
	int	argument;
	
	argument = va_arg(args, int);
	if (argument < 0)
	{
		write(1, "-", 1);
		*prnt_cntr += 1;
		argument *= -1;
	}	
	print_unsigned((unsigned int)argument, prnt_cntr);
	return ;
}

void    print_u(va_list args, s_params *s_info, int *prnt_cntr)
{
	unsigned int	argument;
	
	argument = va_arg(args, unsigned int);
	print_unsigned(argument, prnt_cntr);
	return ;
}

void    print_x(va_list args, s_params *s_info, int *prnt_cntr)
{
	unsigned long int	argument;
	
	argument = va_arg(args, unsigned long int);
	print_hex(argument, s_info, prnt_cntr, 'x');
}

void    print_X(va_list args, s_params *s_info, int *prnt_cntr)
{
	unsigned long int	argument;
	
	argument = va_arg(args, unsigned long int);
	print_hex(argument, s_info, prnt_cntr, 'X');
}

void    print_prcnt(va_list args, s_params *s_info, int *prnt_cntr)
{
	write (1, "%", 1);
	prnt_cntr += 1;	
}
