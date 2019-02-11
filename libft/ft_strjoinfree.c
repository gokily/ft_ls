/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:13:53 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 13:28:11 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, char flag)
{
	char	*ptr;
	int		len;

	if (s1 == 0 || s2 == 0)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	if (!(ptr = ft_strnew(len)))
		return (0);
	ft_strcat(ptr, s1);
	ft_strcat(ptr, s2);
	if (flag & LEFT)
		free(s1);
	if (flag & RIGHT)
		free(s2);
	return (ptr);
}
