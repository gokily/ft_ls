/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_round_double.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 11:40:13 by gly               #+#    #+#             */
/*   Updated: 2019/03/15 13:28:17 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

long double	ft_round_double(long double nb, size_t acc)
{
	size_t		i;
	long double	tmp;

	i = 0;
	tmp = nb;
	while (i < acc)
	{
		tmp *= 10;
		tmp = tmp - (long long)tmp;
		i++;
	}
	if (tmp < 0.5 && tmp > -0.5)
		return (nb);
	tmp = nb >= 0 ? 1 : -1;
	i = 0;
	while (i < acc)
	{
		tmp = (long double)tmp / 10;
		i++;
	}
	return (tmp + nb);
}
