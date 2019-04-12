/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ll2a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/20 13:07:36 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 13:07:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	digit_num(long long n)
{
	int		i;

	if (n == 0)
		return (1);
	i = n < 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char		*ft_ll2a(long long n)
{
	int		power;
	char	*ptr;
	size_t	i;

	power = (n < 0) ? -1 : 1;
	power = n > 9 || n < -9 ? power * 10 : power;
	while (n / power > 9)
		power *= 10;
	if (!(ptr = (char *)malloc(sizeof(*ptr) * (digit_num(n) + 1))))
		return (0);
	i = 0;
	if (n < 0)
	{
		ptr[i] = '-';
		i++;
	}
	while (power != 0)
	{
		ptr[i] = n / power + 48;
		n %= power;
		power /= 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
