/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:54 by gly               #+#    #+#             */
/*   Updated: 2019/04/25 11:42:59 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/incl/libft.h"
#include "libft/incl/ft_printf.h"
#include "ft_ls.h"

static inline void	ft_print_dir_total(t_lfile *file)
{
	unsigned int	size;

	if (file == NULL)
		return ;
	size = 0;
	while (file)
	{
		size += file->file->blkcnt;
		file = file->next;
	}
	ft_printf("total %u\n", size);
	return ;
}

static inline int	ft_getfile_in_dir(t_lfile *ldir, unsigned int flag,
		t_lfile **lfile, t_ls *ls)
{
	DIR				*dir;
	struct dirent	*elem;
	char			*fullpath;
	t_lfile			*lst_elem;

	if (!(dir = opendir(ldir->file->fullpath)))
		return (ft_dir_error(ldir->file->name, ls));
	while ((elem = readdir(dir)))
	{
		if (flag & ALL || elem->d_name[0] != '.')
		{
			fullpath = ft_strjoin_three(ldir->file->fullpath, "/",
					elem->d_name);
			if (!fullpath || !(lst_elem = ft_lfile_new(fullpath, 0, flag, ls)))
			{
				closedir(dir);
				ft_lfile_delall(*lfile);
				return (0);
			}
			ft_lfile_push(lfile, lst_elem);
		}
	}
	closedir(dir);
	return (1);
}

static inline int	ft_print_dir2(t_lfile *dir, t_ls *ls, t_lfile **lfile)
{
	if (ls->flag & FIRST)
		ls->flag ^= FIRST;
	else
		ft_putendl("");
	if (ls->flag & SEVERAL)
		ft_printf("%s:\n", dir->file->fullpath);
	if (!(ft_getfile_in_dir(dir, ls->flag, lfile, ls)))
		return (1);
	ft_lfile_sort(lfile, ls->flag);
	if (ls->flag & REC)
		ls->flag |= SEVERAL;
	if (ls->flag & LNG)
		ft_print_dir_total(*lfile);
	ft_print_lfile(*lfile, ls->flag);
	return (0);
}

int					ft_print_dir(t_lfile *dir, t_ls *ls)
{
	t_lfile		*lfile;
	t_lfile		*tmp;

	lfile = NULL;
	if (ft_print_dir2(dir, ls, &lfile) == 1)
		return (1);
	if (ls->flag & REC)
	{
		tmp = lfile;
		while (tmp != NULL)
		{
			if (S_ISDIR(tmp->file->mode) && ft_strcmp(tmp->file->name, ".")
					&& ft_strcmp(tmp->file->name, ".."))
				if ((ft_print_dir(tmp, ls)))
					return (1);
			tmp = tmp->next;
		}
	}
	ft_lfile_delall(lfile);
	return (0);
}
