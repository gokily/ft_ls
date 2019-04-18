/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 08:48:52 by gly               #+#    #+#             */
/*   Updated: 2019/03/18 17:16:29 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_printf.h"
#include "libft.h"

static void	ft_add_width(char *str, t_conv conv)
{
	char ret[conv.width + 1];

	if (conv.flag & MINUS)
	{
		ft_strncpy(ret, str, conv.len);
		ft_strfill_space(ret, conv.len, conv.width - conv.len);
	}
	else
	{
		ft_strncpy(ret + conv.width - conv.len, str, conv.len);
		if (conv.flag & ZERO)
			ft_strfill_zero(ret, 0, conv.width - conv.len);
		else
			ft_strfill_space(ret, 0, conv.width - conv.len);
	}
	ret[conv.width] = '\0';
	ft_add_to_buffer(ret, conv.width, -1);
}

void		ft_conv_s(t_conv conv, va_list ap)
{
	char	*str;

	str = va_arg(ap, char *);
	conv.len = str == NULL ? 6 : ft_strlen(str);
	conv.len = (conv.flag & ACC) && conv.acc < conv.len ? conv.acc : conv.len;
	if (conv.flag & WDTH && conv.width > conv.len)
	{
		ft_add_width(str == NULL ? "(null)" : str, conv);
	}
	else if (str != NULL)
		ft_add_to_buffer(str, conv.len, -1);
	else
		ft_add_to_buffer("(null)", conv.len, -1);
}
