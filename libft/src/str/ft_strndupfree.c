/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:24:03 by gly               #+#    #+#             */
/*   Updated: 2019/03/04 13:11:50 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndupfree(char *str, size_t len)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = malloc(sizeof(char) * (len + 1))))
	{
		free(str);
		str = NULL;
		return (NULL);
	}
	while (i < len)
	{
		ret[i] = str[i];
		i++;
	}
	ret[i] = '\0';
	free(str);
	str = NULL;
	return (ret);
}
