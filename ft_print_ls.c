/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:30 by gly               #+#    #+#             */
/*   Updated: 2018/12/28 14:52:48 by gly              ###   ########.fr       */
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

int		main(int ac, char **av)
{
	t_ls		*ls;

	ls = ft_parsels(ac, av);
	ft_lfile_sort(&ls->ldir, ls->flag);
	ft_print_ls(ls);
	print_t_ls(ls);
	return (1);
}