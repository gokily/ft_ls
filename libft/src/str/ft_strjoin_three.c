/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_three.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:23:30 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 14:23:55 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "libft.h"

char	*ft_strjoin_three(char *first, char *second, char *third)
{
	char	*ret;
	size_t	len;
	size_t	i;

	len = ft_strlen(first) + ft_strlen(second) + ft_strlen(third);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	ret[len] = '\0';
	len = 0;
	i = 0;
	while (first[i] != '\0')
		ret[len++] = first[i++];
	i = 0;
	while (second[i] != '\0')
		ret[len++] = second[i++];
	i = 0;
	while (third[i] != '\0')
		ret[len++] = third[i++];
	return (ret);
}
