/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:28:35 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 11:17:51 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*ptr;
	size_t	i;

	if (s == 0 || f == 0)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	if (!(ptr = (char *)malloc(sizeof(char) * (i + 1))))
		return (0);
	ptr[i] = '\0';
	i = 0;
	while (s[i] != '\0')
	{
		ptr[i] = f(s[i]);
		i++;
	}
	return (ptr);
}
