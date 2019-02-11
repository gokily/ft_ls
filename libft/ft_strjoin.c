/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:06:23 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 13:12:36 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		len;
	int		i;
	int		j;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ptr = ft_strnew(len)))
		return (0);
	i = 0;
	while (s1[i] != '\0')
	{
		ptr[i] = s1[i];
		i++;
	}
	j = 0;
	while (i < len)
	{
		ptr[i] = s2[j];
		j++;
		i++;
	}
	return (ptr);
}
