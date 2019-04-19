/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsels.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:16 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 15:01:29 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft/incl/libft.h"
#include "libft/incl/ft_printf.h"
#include "ft_ls.h"

static inline t_ls	*ft_parsedir(char *dirpath, t_ls *ls)
{
	t_lfile	*elem;
	char	*path;

	if (!(path = ft_strdup(dirpath)))
		return (NULL);
	if (!(elem = ft_lfile_new(path, LSARG, ls->flag)))
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

static inline void	ft_parseflag2(char *flag, t_ls *ls)
{
	if (*flag == 'C')
		ls->flag |= COLUMN;
	else if (*flag == '1')
		ls->flag = ~(~ls->flag | COLUMN);
	else if (*flag == 'G')
		ls->flag |= COLOR;
	else if (*flag == 'M')
		ls->flag = ~(~ls->flag | COLOR);
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
		else if (*flag == 'u')
			ls->flag |= ATIM;
		else
			ft_parseflag2(flag, ls);
		if (ft_strchr("C1", *flag))
			ls->flag = ~(~ls->flag | LNG);
		flag++;
	}
	return (ls);
}

t_ls				*ft_parsels(int ac, char **av)
{
	t_ls		*ls;
	int			i;
	struct stat	statbuf;

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
			if (lstat(av[i], &statbuf) == -1)
				ls->status = ft_dir_error(av[i]) == 0 ? 1 : 0;
			else if (!(ls = ft_parsedir(av[i], ls)))
				return (NULL);
		}
		i++;
	}
	if (ls->nbdir == 0)
		ls = ft_parsedir(".", ls);
	return (ls);
}
