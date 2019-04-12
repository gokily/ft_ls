/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 10:50:24 by gly               #+#    #+#             */
/*   Updated: 2018/11/20 10:14:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*elem;
	t_list	*start;

	if (lst == 0 || f == 0)
		return (0);
	elem = f(lst);
	if (!(start = ft_lstnew(elem->content, elem->content_size)))
		return (0);
	new = start;
	lst = lst->next;
	while (lst != 0)
	{
		elem = f(lst);
		if (!(new->next = ft_lstnew(elem->content, elem->content_size)))
			return (0);
		lst = lst->next;
		new = new->next;
	}
	return (start);
}
