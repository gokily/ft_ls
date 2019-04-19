/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_manipulators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:06:43 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 17:29:40 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

void	ft_lfile_push(t_lfile **lst, t_lfile *elem)
{
	t_lfile	*tmp;

	if (elem == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = elem;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return ;
}

void	ft_freenull(void *tmp)
{
	free(tmp);
	tmp = NULL;
}

void	ft_lfile_delall(t_lfile *lfile)
{
	t_lfile		*elem;
	t_file		*file;

	elem = lfile;
	while (elem != NULL)
	{
		lfile = elem;
		elem = elem->next;
		file = lfile->file;
		ft_freenull(file->name);
		ft_freenull(file->fullpath);
		ft_freenull(file);
		ft_freenull(lfile);
	}
}
