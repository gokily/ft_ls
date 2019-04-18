/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 16:00:47 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 13:41:50 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

static void	ft_strfill_fract(char *str, int acc, long double fract)
{
	int i;

	i = 0;
	while (i < acc)
	{
		fract *= 10;
		str[i] = fract >= 0 ? (int)fract + '0' : -(int)fract + '0';
		fract -= (int)fract;
		i++;
	}
}

static void	ft_write_float(t_conv conv, long long whole,
		long double fract, int flag)
{
	char	str[flag == 1 ? conv.width + 1 : conv.len + 1];
	int		pos;

	pos = (flag == 1 && conv.flag & MINUS) ? conv.len : 0;
	if (flag == 1)
	{
		if (conv.flag & ZERO && !(conv.flag & MINUS))
			ft_strfill_zero(str + pos, 0, conv.width - conv.len);
		else
			ft_strfill_space(str + pos, 0, conv.width - conv.len);
		pos = pos == 0 ? conv.width - conv.len : 0;
	}
	ft_str_add_flags(str, &pos, conv, whole);
	pos += ft_strfill_ll_base(str + pos, whole, "0123456789");
	str[pos] = '.';
	pos++;
	ft_strfill_fract(str + pos, conv.acc, fract);
	str[flag == 1 ? conv.width : conv.len] = '\0';
	ft_add_to_buffer(str, flag == 1 ? conv.width : conv.len, -1);
}

static void	ft_conv_f2(t_conv conv, long double nb)
{
	long long	whole;
	long double	fract;
	int			flag;

	flag = (nb < 0 || conv.flag & SPACE || conv.flag & PLUS) ? 1 : 0;
	whole = (long long)nb;
	fract = nb - (long double)whole;
	fract = ft_round_double(fract, conv.flag & ACC ? conv.acc : 6);
	if (fract >= 1.0 || fract <= -1.0)
	{
		whole += (long long)fract;
		fract -= nb >= 0 ? 1 : -1;
	}
	conv.acc = conv.flag & ACC ? conv.acc : 6;
	conv.len = ft_longlonglen_base(whole, 10) + 1 + conv.acc + flag;
	ft_write_float(conv, whole, fract, conv.width > conv.len ? 1 : 0);
}

void		ft_conv_f(t_conv conv, va_list ap)
{
	if (conv.flag & LDOUBLE)
		ft_conv_f2(conv, va_arg(ap, long double));
	else
		ft_conv_f2(conv, va_arg(ap, double));
}
