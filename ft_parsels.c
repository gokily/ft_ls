/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:16 by gly               #+#    #+#             */
/*   Updated: 2018/12/28 14:52:18 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_parsedir(char *dirpath, t_ls *ls)
{
	t_lfile	*elem;

	if (!(elem = ft_lfile_new(dirpath, LSARG)))
		return (NULL);
	ft_lfile_push(&ls->ldir, elem);
	return (ls);
}

t_ls	*ft_parseflag(char *flag, t_ls *ls)
{
	flag++;
	while (*flag != '\0')
	{
		if (*flag == 'l')
			ls->flag |= LONG;
		else if (*flag == 'R')
		{
			ls->flag |= REC;
			ls->flag |= SEVERAL;
		}
		else if (*flag == 'a')
			ls->flag |= ALL;
		else if (*flag == 'r')
			ls->flag |= REV;
		else if (*flag == 't')
			ls->flag |= MTIM;
		flag++;
	}
	return (ls);
}

t_ls	*ft_parse_noarg(t_ls *ls)
{
	t_lfile	*elem;

	ls->flag = 0;
	ls->nbdir = 1;
	if (!(elem = ft_lfile_new(".", LSARG)))
		return (NULL);
	ls->ldir = elem;
	return (ls);
}

t_ls	*ft_parsels(int ac, char **av)
{
	t_ls	*ls;
	int		i;

	if(!(ls = ft_t_ls_new()))
		return (NULL);
	i = 1;
	if (ac == 1)
		return (ft_parse_noarg(ls));
	while (i < ac)
	{
		if (av[i][0] == '-')
			ls = ft_parseflag(av[i], ls);
		else
		{
			ls = ft_parsedir(av[i], ls);
			ls->nbdir++;
		}
		i++;
	}
	if (ls->nbdir == 0)
	{
		ft_parsedir(".", ls);
	}
	return (ls);
}
