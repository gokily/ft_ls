/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 09:42:58 by gly               #+#    #+#             */
/*   Updated: 2019/04/18 14:05:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define BUFFSIZE 1024
# include <stdarg.h>

# define FLAG " -+#*.0123456789lhLjzt"
# define CONV "cspdiobuxXfF%"
# define PLUS 1
# define MINUS 1 << 1
# define SPACE 1 << 2
# define POUND 1 << 3
# define ZERO 1 << 4
# define LONG 1 << 5
# define LLNG 1 << 6
# define LDOUBLE 1 << 7
# define SHORT 1 << 8
# define CHAR 1 << 9
# define ACC 1 << 10
# define WDTH 1 << 11
# define JAY 1 << 12
# define ZED 1 << 13
# define TEE 1 << 14

typedef struct	s_conv
{
	int			flag;
	int			width;
	int			acc;
	int			len;
	char		type;
	int			i;
}				t_conv;

int				ft_printf(const char *format, ...);
int				ft_dprintf(int fd, const char *format, ...);

int				ft_add_to_buffer(char *str, int len, int fd);
int				ft_add_str(const char *format, int i);
int				ft_add_conv(const char *format, va_list ap, int i);
int				ft_atoi_pf(const char *str, int *index);
int				ft_strfill_space(char *str, int start, int len);
int				ft_strfill_zero(char *str, int start, int len);
int				ft_strfill_ll_base(char *str, long long nb, char *base);
void			ft_str_add_flags(char *str, int *pos, t_conv conv,
		long long nb);
int				ft_prefix_len(t_conv conv);
void			ft_zero_case(t_conv conv);

void			ft_add_wd_acc_unsigned(unsigned long long nb, t_conv conv,
		int len, int flag);
void			ft_conv_c(t_conv conv, va_list ap);
void			ft_conv_per(t_conv conv);
void			ft_conv_s(t_conv conv, va_list ap);
void			ft_conv_p(t_conv conv, va_list ap);
void			ft_conv_d(t_conv conv, va_list ap);
void			ft_conv_unsigned(t_conv conv, va_list ap);
void			ft_conv_f(t_conv conv, va_list ap);

#endif
