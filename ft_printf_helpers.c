/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 19:58:25 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 20:00:27 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_unsigned(unsigned int num, s_params *s_info)
{
	int	digit;

	digit = num + 48;
	if (num > 9)
	{
		digit = num % 10 + 48;
		print_unsigned(num / 10, s_info);
	}
	write(1, &digit, 1);
	s_info->prnt_cntr += 1;
}

void	print_hex(unsigned long long int num, s_params *s_info)
{
	 int	digit;

	digit = num;
	if (num > 15)
	{	
		digit = num % 16;
		print_hex(num / 16, s_info);
	}
	if (digit >= 0 && digit <= 9)
		digit += '0';
	else if	(s_info->specificator == 'X')
		digit = digit - 10 + 'A';
	else
		digit = digit - 10 + 'a';
	write(1, &digit, 1);
	s_info->prnt_cntr += 1;
}

int fill_list(s_params *s_info,const char *str)
{
    int i;

    i = 1;
    s_info->specificator = 0;
    if (!str[0])
        return (0);
    s_info->specificator = str[i];
    return (i + 1);
}

int print_to(const char *str, s_params *s_info, char end)
{
    int i;
    i = 0;
    while (str && str[i] && (str[i] != end))
    {
        write(1, &str[i], 1);
        i++;
    }
    if (!str)
    {
        write (1, "(null)", 6);
        s_info->prnt_cntr += 6;
    }
    s_info->prnt_cntr += i;
    return (i);
}
