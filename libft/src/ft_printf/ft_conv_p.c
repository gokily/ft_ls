/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_p.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 10:29:15 by gly               #+#    #+#             */
/*   Updated: 2019/03/18 16:54:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

void	ft_conv_p(t_conv conv, va_list ap)
{
	size_t	addr;
	int		len;

	addr = va_arg(ap, size_t);
	if (addr == 0 && conv.flag & ACC && conv.acc == 0)
	{
		conv.width = conv.width > 2 ? conv.width : 2;
		conv.flag |= WDTH;
		ft_zero_case(conv);
		return ;
	}
	conv.len = ft_size_tlen_base(addr, 16);
	len = (conv.acc > conv.len ? conv.acc : conv.len) + 2;
	ft_add_wd_acc_unsigned(addr, conv, len, conv.width > len ? 1 : 0);
}
