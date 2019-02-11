/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:16:44 by gly               #+#    #+#             */
/*   Updated: 2018/11/08 16:35:20 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		i;
	char	*ptr;

	if (s == 0)
		return (0);
	i = 0;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	if (s[i] == '\0')
	{
		if (!(ptr = ft_strnew(0)))
			return (0);
		return (ptr);
	}
	start = i;
	i = ft_strlen((char *)s);
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i--;
	if (!(ptr = ft_strnew(i - start + 1)))
		return (0);
	ptr = ft_strncpy(ptr, s + start, i - start + 1);
	return (ptr);
}
