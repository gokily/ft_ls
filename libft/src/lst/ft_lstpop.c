/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:01:36 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:21:43 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstpop(t_list **alst)
{
	t_list	*last;
	t_list	*elem;

	if (alst == 0 || *alst == 0)
		return (0);
	elem = *alst;
	if (elem->next == 0)
	{
		*alst = 0;
		return (elem);
	}
	while (elem->next->next != 0)
		elem = elem->next;
	last = elem->next;
	elem->next = 0;
	return (last);
}
