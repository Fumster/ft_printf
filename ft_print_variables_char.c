/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_variables_char.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 21:20:29 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 20:03:16 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_c(va_list args, s_params *s_info)
{	
	int	argument;

	argument = va_arg(args, int);
	write (1, &argument, 1);
	s_info->prnt_cntr += 1;
	return ;
}

void	print_s(va_list args, s_params *s_info)

{
	char	*argument;

	argument = va_arg(args, char *);
	print_to((const char *)argument, s_info, 0);
	return ;
}

void	print_prcnt(s_params *s_info)
{
	write (1, "%", 1);
	s_info->prnt_cntr += 1;
}
