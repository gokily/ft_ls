/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convertbase.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 16:28:20 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 13:23:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	valid_base(char *base)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (base[i + 1] != '\0')
	{
		j = i + 1;
		if (base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	digit_num(int n, char *base)
{
	if (n < 0)
		return (ft_intlen_base(n, ft_strlen(base)) + 1);
	else
		return (ft_intlen_base(n, ft_strlen(base)));
}

static int	ft_putsign(char *ptr, int n)
{
	if (n < 0)
	{
		ptr[0] = '-';
		return (1);
	}
	return (0);
}

char		*ft_convertbase(int n, char *base)
{
	int		i;
	int		power;
	char	*ptr;

	if (valid_base(base) == 0)
		return (NULL);
	power = (n < 0) ? -1 : 1;
	power = n > 9 || n < -9 ? power * 10 : power;
	while (n / power > 9)
		power *= 10;
	if (!(ptr = (char *)malloc(sizeof(char) * (digit_num(n, base) + 1))))
		return (NULL);
	i = 0;
	i = ft_putsign(ptr, n);
	while (power != 0)
	{
		ptr[i] = base[n / power];
		n %= power;
		power /= 10;
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
