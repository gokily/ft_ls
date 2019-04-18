/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_common.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 13:52:56 by gly               #+#    #+#             */
/*   Updated: 2019/03/20 13:10:46 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int			ft_prefix_len(t_conv conv)
{
	if (conv.type == 'p')
		return (2);
	else if (conv.flag & POUND)
	{
		if ((conv.type == 'o' && conv.acc <= conv.len) || conv.type == 'b')
			return (1);
		else if (ft_strchr("xX", conv.type))
			return (2);
	}
	return (0);
}

static int	ft_putprefix(unsigned long long nb, char *str, int pos, t_conv conv)
{
	int		len;

	if ((nb == 0 && conv.type != 'p') ||
			(conv.type == 'o' && conv.acc > conv.len))
		return (pos);
	len = ft_prefix_len(conv);
	str += pos;
	if (conv.type == 'p')
		ft_strncpy(str, "0x", 2);
	else if (conv.flag & POUND)
	{
		if (conv.type == 'b')
			ft_strncpy(str, "b", 1);
		else if (conv.type == 'o')
			ft_strncpy(str, "0", 1);
		else if (conv.type == 'x')
			ft_strncpy(str, "0x", 2);
		else if (conv.type == 'X')
			ft_strncpy(str, "0X", 2);
	}
	return (pos + len);
}

static int	ft_strfill_llu_base(char *str, unsigned long long nb, char *base)
{
	int					i;
	unsigned long long	l_base;
	unsigned long long	power;

	l_base = ft_strlen(base);
	power = 1;
	i = 0;
	while (nb / power >= l_base)
		power *= l_base;
	while (power > 0)
	{
		str[i] = base[nb / power];
		nb %= power;
		power /= l_base;
		i++;
	}
	return (i);
}

static void	ft_strfill_nb(char *str, unsigned long long nb, t_conv conv)
{
	if (conv.type == 'u')
		ft_strfill_llu_base(str, nb, "0123456789");
	else if (conv.type == 'o')
		ft_strfill_llu_base(str, nb, "01234567");
	else if (conv.type == 'b')
		ft_strfill_llu_base(str, nb, "01");
	else if (conv.type == 'x' || conv.type == 'p')
		ft_strfill_llu_base(str, nb, "0123456789abcdef");
	else if (conv.type == 'X')
		ft_strfill_llu_base(str, nb, "0123456789ABCDEF");
}

void		ft_add_wd_acc_unsigned(unsigned long long nb, t_conv conv,
		int len, int flag)
{
	char	str[flag == 1 ? conv.width + 1 : len + 1];
	int		pos;

	pos = (flag == 1 && conv.flag & MINUS) ? len : 0;
	if (flag == 1)
	{
		if (conv.flag & ZERO && !(conv.flag & ACC) && !(conv.flag & MINUS))
		{
			pos = ft_putprefix(nb, str, pos, conv);
			ft_strfill_zero(str + pos, 0, conv.width - len);
			flag = 2;
		}
		else
			ft_strfill_space(str + pos, 0, conv.width - len);
		pos = (pos == 0 || flag == 2) ? conv.width - len + pos : 0;
	}
	if (flag != 2)
		pos = ft_putprefix(nb, str, pos, conv);
	if (conv.acc > conv.len)
		pos = ft_strfill_zero(str, pos, conv.acc - conv.len);
	ft_strfill_nb(str + pos, nb, conv);
	str[flag >= 1 ? conv.width : len] = '\0';
	ft_add_to_buffer(str, flag >= 1 ? conv.width : len, -1);
}
