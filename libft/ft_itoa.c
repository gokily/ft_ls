/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 18:02:50 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:09:56 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	digit_num(int n)
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

char		*ft_itoa(int n)
{
	int		power;
	char	*ptr;
	int		i;

	power = (n < 0) ? -1 : 1;
	power = ft_intabs(n) > 9 ? power * 10 : power;
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
