/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:16 by gly               #+#    #+#             */
/*   Updated: 2019/04/18 13:56:07 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline t_ls	*ft_parsedir(char *dirpath, t_ls *ls)
{
	t_lfile	*elem;
	char	*path;

	if (!(path = ft_strdup(dirpath)))
		return (NULL);
	if (!(elem = ft_lfile_new(path, LSARG)))
		return (NULL);
	ft_lfile_push(&ls->ldir, elem);
	return (ls);
}

static inline void	ft_check_illegal_flag(char *flag, t_ls *ls)
{
	int		i;

	i = 0;
	while (flag[i] != '\0')
	{
		if (ft_strchr(LSOPTION, flag[i]) == NULL)
		{
			ft_dprintf(STDERR_FILENO,
					"ls: illegal option -- %c\nusage: ls [-%s] [file ...]\n",
					flag[i], LSOPTION);
			free(ls);
			ls = NULL;
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

static inline t_ls	*ft_parseflag(char *flag, t_ls *ls)
{
	ft_check_illegal_flag(flag, ls);
	while (*flag != '\0')
	{
		if (*flag == 'l')
			ls->flag |= LNG;
		else if (*flag == 'R')
			ls->flag |= REC;
		else if (*flag == 'a')
			ls->flag |= ALL;
		else if (*flag == 'r')
			ls->flag |= REV;
		else if (*flag == 't')
			ls->flag |= MTIM;
		else if (*flag == 'C')
			ls->flag |= COLUMN;
		else if (*flag == '1')
			ls->flag = ~(~ls->flag | COLUMN);
		else if (*flag == 'G')
			ls->flag |= COLOR;
		else if (*flag == 'M')
			ls->flag = ~(~ls->flag | COLOR);
		if (ft_strchr("C1", *flag))
			ls->flag = ~(~ls->flag | LNG);
		flag++;
	}
	return (ls);
}

static inline int	ft_check_dir_exist(char *filename)
{
	struct stat statbuf;

	if (lstat(filename, &statbuf) == -1)
	{
		ft_dir_error(filename);
		return (0);
	}
	return (1);
}

t_ls				*ft_parsels(int ac, char **av)
{
	t_ls	*ls;
	int		i;

	if (!(ls = ft_t_ls_new()))
		return (NULL);
	i = 1;
	while (i < ac)
	{
		if (ls->nbdir == 0 && av[i][0] == '-')
			ls = ft_parseflag(av[i] + 1, ls);
		else
		{
			ls->nbdir++;
			if (ft_check_dir_exist(av[i]) == 0)
				ls->status = 1;
			else if (!(ls = ft_parsedir(av[i], ls)))
				return (NULL);
		}
		i++;
	}
	if (ls->nbdir == 0)
		ls = ft_parsedir(".", ls);
	return (ls);
}
