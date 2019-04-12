/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:43:55 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:42:51 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*tmp;
	unsigned char	*ptr;
	size_t			i;

	ptr = (unsigned char *)dest;
	tmp = (unsigned char *)src;
	i = 0;
	if (dest > src)
	{
		while (n >= 1)
		{
			n--;
			ptr[n] = tmp[n];
		}
	}
	else
	{
		while (i < n)
		{
			ptr[i] = tmp[i];
			i++;
		}
	}
	return (dest);
}
