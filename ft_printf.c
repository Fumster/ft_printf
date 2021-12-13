/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:00 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 20:03:43 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list args, s_params *s_info)
{
	if (s_info->specificator == 'c')
		print_c(args, s_info);
	else if (s_info->specificator == 's')
		print_s(args, s_info);
	else if (s_info->specificator == 'p')
		print_p(args, s_info);
	else if (s_info->specificator == 'd' ||
			s_info->specificator == 'i')
		print_int(args, s_info);
	else if (s_info->specificator == 'u')
		print_u(args, s_info);
	else if (s_info->specificator == 'x')
		print_x(args, s_info);
	else if (s_info->specificator == 'X')
		print_upper_x(args, s_info);
	else if (s_info->specificator == '%')
		print_prcnt(s_info);
}

int	ft_printf(const char *p_string, ...)
{
	int			brkpnt;
	s_params	s_info;
	va_list		args;

	brkpnt = 0;
	s_info.prnt_cntr = 0;
	va_start(args, p_string);
	while (p_string[brkpnt])
	{
		brkpnt += print_to(p_string + brkpnt, &s_info, '%');
		brkpnt += fill_list(&s_info, p_string + brkpnt);
		print_args(args, &s_info);
	}
	va_end(args);
	return (s_info.prnt_cntr);
}
