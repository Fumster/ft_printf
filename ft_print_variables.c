/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pinting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/02 21:38:36 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	return ;
}

void    print_X(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}

void    print_prcnt(va_list args, s_params *s_info, int *prnt_cntr)
{
	return ;
}
