/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_longlonglen_base.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:07:48 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 14:39:33 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_longlonglen_base(long long n, int base)
{
	size_t		i;
	long long	power;

	i = 1;
	power = n < 0 ? -1 : 1;
	if (n <= -base || n >= base)
	{
		i++;
		power *= base;
	}
	while ((n / power) >= base)
	{
		i++;
		power *= base;
	}
	return (i);
}
