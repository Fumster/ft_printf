/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:00 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/02 21:38:38 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list args, s_params *s_info, int *prnt_cntr)
{
	if (s_info->specificator[0] == 'c')
		print_c(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 's')
		print_s(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'p')
		print_p(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'd')
		print_d(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'i')
		print_i(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'u')
		print_u(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'x')
		print_x(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == 'X')
		print_X(args, s_info, prnt_cntr);
	if (s_info->specificator[0] == '%')
		print_prcnt(args, s_info, prnt_cntr);
}

int	fill_list(s_params *s_info,const char *str)
{
	int	i;

	i = 1;
	s_info->width = 0;
	s_info->precision = 0;
	s_info->specificator[0] = 0;
	if (!str[0])
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		s_info->width = (s_info->width * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		s_info->precision = (s_info->precision * 10) + (str[i] - 48);
		i++;
	}
	s_info->specificator[0] = str[i];
	return (i + 1);
}

int print_to(const char *str, int *prnt_cntr, char end)
{
	int	i;
	i = 0;
	while (str[i] && (str[i] != end))
	{
		write(1, &str[i], 1);
		i++;
	}
	*prnt_cntr += i;
	return (i);
}

int	ft_printf(const char *p_string, ...)
{
	int			brkpnt;
	int			prnt_cntr;
	s_params	s_info;
	va_list		args;

	brkpnt = 0;
	prnt_cntr = 0;
	va_start(args, p_string);
	//va_arg(agrs, int) - take next argument by its type
	while (p_string[brkpnt])
	{
		brkpnt += print_to(p_string + brkpnt, &prnt_cntr, '%');
		brkpnt += fill_list(&s_info, p_string + brkpnt);
		print_args(args, &s_info, &prnt_cntr);
	}
	va_end(args);
	return (prnt_cntr);
}
