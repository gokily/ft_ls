/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulllen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:01:40 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 14:26:33 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_ulllen_base(unsigned long long n, unsigned int base)
{
	size_t				i;
	unsigned long long	power;

	i = 1;
	power = 1;
	while ((n / power) >= base)
	{
		i++;
		power *= base;
	}
	return (i);
}
