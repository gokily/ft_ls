/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:30 by gly               #+#    #+#             */
/*   Updated: 2019/04/16 16:22:21 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline t_lfile	*ft_find_first_real_dir(t_lfile *ldir, t_lfile **lfile)
{
	t_lfile		*tmp;

	*lfile = ldir;
	while (ldir != NULL && !(S_ISDIR(ldir->next->file->mode)))
	{
		ldir = ldir->next;
	}
	if (ldir != NULL)
	{
		tmp = ldir;
		ldir = ldir->next;
		tmp->next = NULL;
	}
	return (ldir);
}

static inline void ft_print_false_dir(t_lfile *lfile, t_ls *ls)
{
	ft_print_lfile(lfile, ls->flag);
	ft_lfile_delall(lfile);
}

static inline t_ls	*ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;
	t_lfile	*lfile;

	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	if (!(S_ISDIR(ls->ldir->file->mode)))
	{
		ls->flag ^= FIRST;
		ls->ldir = ft_find_first_real_dir(ls->ldir, &lfile);
		ft_print_false_dir(lfile, ls);
	}
	ldir = ls->ldir;
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
	ls->flag |= LDIR;
	ft_lfile_sort(&ls->ldir, ls->flag);
	ls->flag ^= LDIR;
	ls = ft_print_ls(ls);
	status = ls->status;
	ft_freels(ls);
	return (status);
}
