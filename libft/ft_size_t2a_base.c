/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_size_t2a_base.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:54:02 by gly               #+#    #+#             */
/*   Updated: 2018/12/20 13:05:53 by gly              ###   ########.fr       */
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

char		*ft_size_t2a_base(size_t nb, char *base)
{
	size_t	power;
	size_t	n_base;
	char	*ret;
	size_t	i;

	power = 1;
	n_base = ft_strlen(base);
	if (n_base <= 1 || valid_base(base) == 0)
		return (NULL);
	while (nb / power >= n_base)
		power *= n_base;
	if (!(ret = malloc(sizeof(char) * (ft_size_tlen_base(nb, n_base) + 1))))
		return (NULL);
	i = 0;
	while (power > 0)
	{
		ret[i] = base[nb / power];
		nb %= power;
		power /= n_base;
		i++;
	}
	ret[i] = '\0';
	return (ret);
}
