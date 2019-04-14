/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:30 by gly               #+#    #+#             */
/*   Updated: 2019/04/14 15:21:46 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//Voir si on ne veut pas un retour pour ft_print_dir
void	ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;

	ldir = ls->ldir;
	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	while (ldir != NULL)
	{
		ft_print_dir(ldir, ls);
		ldir = ldir->next;
	}
	return ;
}

void	ft_freels(t_ls *ls)
{
	t_lfile	*ldir;

	ldir = ls->ldir;
	ft_lfile_delall(ldir);
	free(ls);
	ls = NULL;
}

int		main(int ac, char **av)
{
	t_ls		*ls;

	if (!(ls = ft_parsels(ac, av)))
		return (0);
	ft_lfile_sort(&ls->ldir, ls->flag);
	ft_print_ls(ls);
	ft_freels(ls);
	return (1);
}
