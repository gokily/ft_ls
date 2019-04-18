/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 09:05:57 by gly               #+#    #+#             */
/*   Updated: 2019/03/20 13:20:07 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"

int		ft_strfill_space(char *str, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[start] = ' ';
		start++;
		i++;
	}
	return (start);
}

int		ft_strfill_zero(char *str, int start, int len)
{
	int		i;

	i = 0;
	while (i < len)
	{
		str[start] = '0';
		start++;
		i++;
	}
	return (start);
}

void	ft_zero_case(t_conv conv)
{
	char	str[conv.width + 1];
	int		pos;

	if (!(conv.flag & WDTH) && (conv.type != 'o' || !(conv.flag & POUND)))
		return ;
	pos = conv.flag & MINUS ? 1 : 0;
	ft_strfill_space(str, pos, conv.width - 1);
	pos = conv.flag & MINUS ? 0 : conv.width - 1;
	if ((conv.flag & POUND) && (conv.type == 'o'))
		str[pos] = '0';
	else if (conv.type == 'p')
	{
		pos = pos == 0 ? pos : pos - 1;
		str[pos] = '0';
		str[pos + 1] = 'x';
	}
	else
		str[pos] = ' ';
	ft_add_to_buffer(str, conv.width, -1);
}

int		ft_atoi_pf(const char *str, int *index)
{
	int i;
	int	nb;

	i = *index;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		i++;
	}
	*index = i - 1;
	return (nb);
}
