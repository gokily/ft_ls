/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_conv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 12:45:24 by gly               #+#    #+#             */
/*   Updated: 2019/03/20 13:27:32 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

void	ft_make_conv(t_conv conv, va_list ap)
{
	if (conv.type == 'c')
		ft_conv_c(conv, ap);
	else if (conv.type == 's')
		ft_conv_s(conv, ap);
	else if (conv.type == 'p')
		ft_conv_p(conv, ap);
	else if (conv.type == 'i' || conv.type == 'd')
		ft_conv_d(conv, ap);
	else if (ft_strchr("uoxXb", conv.type))
		ft_conv_unsigned(conv, ap);
	else if (conv.type == 'f' || conv.type == 'F')
		ft_conv_f(conv, ap);
	else if (conv.type == '%')
		ft_conv_per(conv);
}

t_conv	ft_parse_mod(const char *format, int i, t_conv conv)
{
	if (format[i] == 'l')
	{
		if (format[i + 1] == 'l')
			conv.flag |= LLNG;
		else if (!(conv.flag & LLNG))
			conv.flag |= LONG;
	}
	else if (format[i] == 'h')
	{
		if (format[i + 1] == 'h')
			conv.flag |= CHAR;
		else if (!(conv.flag & CHAR))
			conv.flag |= SHORT;
	}
	else if (format[i] == 'L')
		conv.flag |= LDOUBLE;
	else if (format[i] == 'j')
		conv.flag |= JAY;
	else if (format[i] == 'z')
		conv.flag |= ZED;
	else if (format[i] == 't')
		conv.flag |= TEE;
	return (conv);
}

t_conv	ft_parse_acc_wd(const char *format, va_list ap, t_conv conv)
{
	int		n;

	conv.flag |= (format[conv.i] == '*' ||
		(format[conv.i] >= '1' && format[conv.i] <= '9')) ? WDTH : 0;
	if (format[conv.i] == '*')
	{
		n = va_arg(ap, int);
		conv.width = n < 0 ? -n : n;
		conv.flag |= n < 0 ? MINUS : 0;
	}
	else if (format[conv.i] >= '1' && format[conv.i] <= '9')
		conv.width = ft_atoi_pf(format, &conv.i);
	else if (format[conv.i] == '.')
	{
		conv.flag |= ACC;
		if (format[++conv.i] == '*')
		{
			n = va_arg(ap, int);
			conv.acc = n > 0 ? n : 0;
			conv.flag ^= n < 0 ? ACC : 0;
		}
		else
			conv.acc = ft_atoi_pf(format, &conv.i);
	}
	return (conv);
}

t_conv	ft_parse_flag(const char *format, va_list ap, t_conv conv)
{
	while (format[conv.i] != '\0' && ft_strchr(FLAG, format[conv.i]))
	{
		if (format[conv.i] == '-')
			conv.flag |= MINUS;
		else if (format[conv.i] == '+')
			conv.flag |= PLUS;
		else if (format[conv.i] == '#')
			conv.flag |= POUND;
		else if (format[conv.i] == ' ')
			conv.flag |= SPACE;
		else if (format[conv.i] == '0')
			conv.flag |= ZERO;
		else
		{
			conv = ft_parse_mod(format, conv.i, conv);
			conv = ft_parse_acc_wd(format, ap, conv);
		}
		conv.i++;
	}
	conv.type = ft_strchr(CONV, format[conv.i]) ? format[conv.i] : 0;
	return (conv);
}

int		ft_add_conv(const char *format, va_list ap, int i)
{
	t_conv	conv;

	conv.i = i;
	conv.acc = 0;
	conv.width = 1;
	conv.flag = 0;
	conv.len = 0;
	conv = ft_parse_flag(format, ap, conv);
	if (conv.type == 0)
		return (ft_add_str(format, conv.i));
	ft_make_conv(conv, ap);
	return (conv.i + 1);
}
