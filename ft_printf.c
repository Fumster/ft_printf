/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:00 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/01 21:28:47 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_args(va_list args, s_list *s_info, int *prnt_cntr)
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

int	fill_list(s_params *s_info, char *str)
{
	int	i;

	i = 1;
	info->width = 0;
	info->precision = 0;
	info->specificator = 0;
	if (!str[0])
		return (0);
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		info->width = (info->width * 10) + (str[i] - 48);
		i++;
	}
	if (str[i] == '.')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		info->precision = (info->precision * 10) + (str[i] - 48);
		i++;
	}
	info->specificator[0] = str[i];
	return (i + 1);
}

int print_to(char *str, int *prnt_cntr, char end)
{
	int	i;
	i = 0;
	while (str[i] && (str[i] != end))
	{
		write(1, &str[i], 1);
		i++;
	}
	*prnt_cnt + i;
	return (i);
}

int	ft_printf(const char *p_string, ...)
{
	int			brkpnt;
	int			prnt_cntr;
	s_params	s_info;
	va_list		args;

	pcnt_pos = 0;
	prnt_cnt = 0;
	va_start(args, p_string);
	//va_arg(agrs, int) - take next argument by its type
	while (p_string[brkpnt])
	{
		brkpnt += print_to(&p_string[brkpnt], &prnt_cntr, '%');
		brkpnt += fill_list(&s_info, &p_string[brkpnt]);
		print_args(args, &s_info, &prnt_cntr)
	}
	va_end(args);
	return (prnt_cnt);
}
