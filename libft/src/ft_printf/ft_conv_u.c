/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_u.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 14:05:18 by gly               #+#    #+#             */
/*   Updated: 2019/03/20 13:19:45 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include "ft_printf.h"
#include "libft.h"

static int	ft_baselen(t_conv conv)
{
	if (conv.type == 'u')
		return (10);
	else if (conv.type == 'o')
		return (8);
	else if (conv.type == 'b')
		return (2);
	else if (conv.type == 'x' || conv.type == 'X')
		return (16);
	return (0);
}

static void	ft_conv_u2(t_conv conv, unsigned long long nb)
{
	int		len;
	int		prefix_len;

	if (nb == 0 && (conv.flag & ACC && conv.acc == 0))
		ft_zero_case(conv);
	else
	{
		if (conv.flag & CHAR)
			nb = (unsigned char)nb;
		else if (conv.flag & SHORT)
			nb = (unsigned short)nb;
		conv.len = ft_ulllen_base(nb, ft_baselen(conv));
		prefix_len = nb == 0 ? 0 : ft_prefix_len(conv);
		len = (conv.acc > conv.len ? conv.acc : conv.len) + prefix_len;
		ft_add_wd_acc_unsigned(nb, conv, len, conv.width > len ? 1 : 0);
	}
}

void		ft_conv_unsigned(t_conv conv, va_list ap)
{
	if (conv.flag & JAY)
		ft_conv_u2(conv, va_arg(ap, uintmax_t));
	else if (conv.flag & LLNG)
		ft_conv_u2(conv, va_arg(ap, unsigned long long));
	else if (conv.flag & ZED)
		ft_conv_u2(conv, va_arg(ap, size_t));
	else if (conv.flag & LONG)
		ft_conv_u2(conv, va_arg(ap, unsigned long));
	else if (conv.flag & TEE)
		ft_conv_u2(conv, va_arg(ap, ptrdiff_t));
	else
		ft_conv_u2(conv, va_arg(ap, unsigned int));
}
