/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:54 by gly               #+#    #+#             */
/*   Updated: 2019/04/01 14:50:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_dir_total(t_lfile *file)
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
	printf("total %u\n", size);
	return ;
}

static int		ft_getfile_in_dir(t_lfile *ldir, unsigned char flag,
		t_lfile **lfile)
{
	DIR				*dir;
	struct dirent	*elem;
	char			*fullpath;
	t_lfile			*lst_elem;

	if (!(dir = opendir(ldir->file->fullpath)))
		return (ft_dir_error(1));
	while ((elem = readdir(dir)))
	{
		if (flag & ALL || elem->d_name[0] != '.')
		{
			fullpath = ft_strjoin_three(ldir->file->fullpath, "/", elem->d_name);
			if (!fullpath || !(lst_elem = ft_lfile_new(fullpath, 0)))
			{
				closedir(dir);
				ft_lfile_delall(*lfile);
				return (ft_dir_error(2));
			}
			ft_lfile_push(lfile, lst_elem);
		}
	}
	closedir(dir);
	return (1);
}

//La fonciton recursive
int			ft_print_dir(t_lfile *dir, t_ls *ls)
{
	static int	first = 1;
	t_lfile		*lfile;

	lfile = NULL;
	if (!(ft_getfile_in_dir(dir, ls->flag, &lfile)))
		return (0);
	ft_lfile_sort(&lfile, ls->flag);
	if (first == 1)
		first = 0;
	else
		ft_putendl("");
	if (ls->flag & SEVERAL)
		printf("%s:\n", dir->file->fullpath);
	if (ls->flag & REC)
		ls->flag |= SEVERAL;
	if (ls->flag & LONG)
		ft_print_dir_total(lfile);
	ft_print_lfile(lfile, ls->flag);
	if (ls->flag & REC)
	{
		while (lfile != NULL)
		{
			if (S_ISDIR(lfile->file->mode) && ft_strcmp(lfile->file->name, ".") && 
					ft_strcmp(lfile->file->name, ".."))
				if(!(ft_print_dir(lfile, ls)))
					return (0);
			lfile = lfile->next;
		}
	}
	return (1);
}
