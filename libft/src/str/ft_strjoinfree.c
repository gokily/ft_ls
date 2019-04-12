/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 13:13:53 by gly               #+#    #+#             */
/*   Updated: 2019/03/04 13:12:13 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, char flag)
{
	char	*ptr;
	int		len;

	if (s1 != NULL && s2 != NULL)
	{
		len = ft_strlen(s1) + ft_strlen(s2);
		if (!(ptr = ft_strnew(len)))
			return (NULL);
		ft_strcat(ptr, s1);
		ft_strcat(ptr, s2);
	}
	else
		ptr = NULL;
	if (flag & LEFT)
	{
		free(s1);
		s1 = NULL;
	}
	if (flag & RIGHT)
	{
		free(s2);
		s2 = NULL;
	}
	return (ptr);
}
