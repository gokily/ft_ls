/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:30 by gly               #+#    #+#             */
/*   Updated: 2019/04/16 13:32:16 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//Voir si on ne veut pas un retour pour ft_print_dir
static inline t_ls	*ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;

	ldir = ls->ldir;
	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	while (ldir != NULL)
	{
		ls->status |= ft_print_dir(ldir, ls);
		ldir = ldir->next;
	}
	return (ls);
}

void				ft_freels(t_ls *ls)
{
	t_lfile	*ldir;

	ldir = ls->ldir;
	ft_lfile_delall(ldir);
	free(ls);
	ls = NULL;
}

int					main(int ac, char **av)
{
	t_ls		*ls;
	int			status;

	if (!(ls = ft_parsels(ac, av)))
		return (1);
	ft_lfile_sort(&ls->ldir, ls->flag);
	ls = ft_print_ls(ls);
	status = ls->status;
	ft_freels(ls);
	return (status);
}
