/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:37:01 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/02 20:40:42 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int		width;
	int		precision;
	char	specificator[1];

}	s_params;

int		ft_printf(const char *p_string, ...);
int		print_to(const char *str, int *prnt_cntr, char end);
int		fill_list(s_params *s_info,const char *str);
void    print_c(va_list args, s_params *s_info, int *prnt_cntr);
void    print_s(va_list args, s_params *s_info, int *prnt_cntr);
void    print_p(va_list args, s_params *s_info, int *prnt_cntr);
void    print_d(va_list args, s_params *s_info, int *prnt_cntr);
void    print_i(va_list args, s_params *s_info, int *prnt_cntr);
void    print_u(va_list args, s_params *s_info, int *prnt_cntr);
void    print_x(va_list args, s_params *s_info, int *prnt_cntr);
void    print_X(va_list args, s_params *s_info, int *prnt_cntr);
void    print_prcnt(va_list args, s_params *s_info, int *prnt_cntr);
#endif
