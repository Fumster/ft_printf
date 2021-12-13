/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 21:37:01 by fchrysta          #+#    #+#             */
/*   Updated: 2021/12/13 20:12:20 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_list
{
	int		prnt_cntr;
	char	specificator;

}	s_params;

int		ft_printf(const char *p_string, ...);
void    print_args(va_list args, s_params *s_info);
int		print_to(const char *str, s_params *s_info, char end);
int		fill_list(s_params *s_info, const char *str);
void    print_c(va_list args, s_params *s_info);
void    print_s(va_list args, s_params *s_info);
void    print_p(va_list args, s_params *s_info);
void    print_int(va_list args, s_params *s_info);
void    print_u(va_list args, s_params *s_info);
void    print_x(va_list args, s_params *s_info);
void    print_upper_x(va_list args, s_params *s_info);
void    print_prcnt(s_params *s_info);
void    print_unsigned(unsigned int num, s_params *s_info);
void    print_hex(unsigned long long int num, s_params *s_info);







#endif
