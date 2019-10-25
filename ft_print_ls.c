/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:30 by gly               #+#    #+#             */
/*   Updated: 2019/04/23 15:43:22 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

static inline t_lfile	*ft_find_first_real_dir(t_lfile *ldir, t_lfile **lfile)
{
	t_lfile		*tmp;

	*lfile = ldir;
	while (ldir != NULL && !(S_ISDIR(ldir->file->mode)))
	{
		tmp = ldir;
		ldir = ldir->next;
	}
	if (ldir != NULL)
		tmp->next = NULL;
	return (ldir);
}

static inline t_ls		*ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;
	t_lfile	*lfile;

	lfile = NULL;
	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	if (!(S_ISDIR(ls->ldir->file->mode)) && !(ls->ldir->file->flag & DIRLNK))
	{
		ls->flag ^= FIRST;
		ls->ldir = ft_find_first_real_dir(ls->ldir, &lfile);
		ft_lfile_sort(&lfile, ls->flag);
		ft_print_lfile(lfile, ls->flag);
		ft_lfile_delall(lfile);
	}
	ldir = ls->ldir;
	while (ldir != NULL)
	{
		ls->status |= ft_print_dir(ldir, ls);
		ldir = ldir->next;
	}
	return (ls);
}

static inline int		ft_freels(t_ls *ls)
{
	int		status;

	ft_lfile_delall(ls->ldir);
	status = ls->status;
	free(ls);
	ls = NULL;
	return (status);
}

int						main(int ac, char **av)
{
	t_ls		*ls;

	if (!(ls = ft_parsels(ac, av)))
		return (1);
	if (ls->ldir == NULL)
		return (ft_freels(ls));
	ft_lfile_sort(&ls->ldir, LDIR | ls->flag);
	ls = ft_print_ls(ls);
	return (ft_freels(ls));
}
