/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_cper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:50:45 by gly               #+#    #+#             */
/*   Updated: 2019/03/20 13:18:51 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_width_char(char c, int width, int flag, int zero)
{
	char	str[width + 1];
	int		i;
	char	fill;

	i = 0;
	fill = flag || !zero ? ' ' : '0';
	while (i < width)
	{
		str[i] = fill;
		i++;
	}
	if (flag)
		str[0] = c;
	else
		str[width - 1] = c;
	str[width] = '\0';
	ft_add_to_buffer(str, width, -1);
}

void		ft_conv_per(t_conv conv)
{
	ft_add_width_char('%', conv.width > 1 ? conv.width : 1,
			conv.flag & MINUS, !!(conv.flag & ZERO));
}

void		ft_conv_c(t_conv conv, va_list ap)
{
	char c;

	c = va_arg(ap, int);
	ft_add_width_char(c, conv.width > 1 ? conv.width : 1, conv.flag & MINUS,
			!!(conv.flag & ZERO));
}
