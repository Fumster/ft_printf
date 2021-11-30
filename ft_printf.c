/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:28:00 by fchrysta          #+#    #+#             */
/*   Updated: 2021/11/30 21:49:15 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int print_to_pcnt(char *str, int *prnt_cnt)
{
	int	i;
	i = 0;
	while (str[i] && (str[i] != '%'))
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
	int			prnt_cnt;
	s_params	info;
	va_list		args;

	pcnt_pos = 0;
	prnt_cnt = 0;
	va_start(args, p_string);
	//va_arg(agrs, int) - take next argument by its type
	while (p_string[brkpnt])
	{
		brkpnt += print_to_pcnt(&p_string[brkpnt], &prnt_cnt);
		brkpnt += fill_list(info, &p_string[brkpnt]);
		print_variable(args, &prnt_cnt)
	}
	va_end(args);
	return (prnt_cnt);
}
