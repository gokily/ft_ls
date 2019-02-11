/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:34:43 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:11:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*next;
	t_list	*current;

	if (!alst || !del)
		return ;
	current = *alst;
	while (current != 0)
	{
		next = current->next;
		ft_lstdelone(&current, del);
		current = next;
	}
	*alst = 0;
}
