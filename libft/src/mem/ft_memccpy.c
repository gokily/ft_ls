/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:28:47 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:23:16 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*tmp;
	unsigned char	*src2;

	i = 0;
	tmp = (unsigned char *)dest;
	src2 = (unsigned char *)src;
	while (i < n)
	{
		tmp[i] = src2[i];
		if (src2[i] == (unsigned char)c)
			return (tmp + i + 1);
		i++;
	}
	return (0);
}
