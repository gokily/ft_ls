/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_common.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 13:35:22 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 18:05:40 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int		ft_strfill_ll_base(char *str, long long nb, char *base)
{
	int			i;
	long long	l_base;
	long long	power;

	l_base = ft_strlen(base);
	power = nb >= 0 ? 1 : -1;
	power *= (nb >= l_base || nb <= -l_base) ? l_base : 1;
	i = 0;
	while (nb / power >= l_base)
		power *= l_base;
	while (power != 0)
	{
		str[i] = base[nb / power];
		nb %= power;
		power /= l_base;
		i++;
	}
	return (i);
}

void	ft_str_add_flags(char *str, int *pos, t_conv conv, long long nb)
{
	if (nb < 0)
	{
		str[*pos] = '-';
		(*pos)++;
	}
	else if (conv.flag & PLUS)
	{
		str[*pos] = '+';
		(*pos)++;
	}
	else if (conv.flag & SPACE)
	{
		str[*pos] = ' ';
		(*pos)++;
	}
}
