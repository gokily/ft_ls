/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:16 by gly               #+#    #+#             */
/*   Updated: 2019/03/08 11:32:59 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_parsedir(char *dirpath, t_ls *ls)
{
	t_lfile	*elem;

	if (!(elem = ft_lfile_new(dirpath, LSARG)))
		return (NULL);
	ft_lfile_push(&ls->ldir, elem);
	ls->nbdir++;
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
			ls->flag |= REC;
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

t_ls	*ft_parsels(int ac, char **av)
{
	t_ls	*ls;
	int		i;
	int		flag;

	if(!(ls = ft_t_ls_new()))
		return (NULL);
	i = 1;
	flag = 0;
	while (i < ac)
	{
		if (flag == 0 && av[i][0] == '-')
			ls = ft_parseflag(av[i], ls);
		else
		{
			if (!(ls = ft_parsedir(av[i], ls)))
				return (NULL);
			flag = 1;
		}
		i++;
	}
	if (ls->nbdir == 0)
		ls = ft_parsedir(".", ls);
	return (ls);
}
