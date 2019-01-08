/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dir.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:52:54 by gly               #+#    #+#             */
/*   Updated: 2018/12/28 16:19:40 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		ft_print_dir_total(t_lfile *file)
{
	unsigned int	size;

	size = 0;
	while (file)
	{
		size += file->blkcnt;
		file = file->next;
	}
	ft_printf("total %u\n", size);
	return ;
}

static t_lfile	*ft_getfile(t_lfile *ldir)
{
	DIR				*dir;
	struct dirent	*elem;
	char			*fullpath;
	t_lfile			*lst_elem;
	t_lfile			*lfile;

	lfile = NULL;
	if (!(dir = opendir(ldir->fullpath)))
		return (ft_dir_error(1));
	while ((elem = readdir(dir)))
	{
		fullpath = ft_strjoin_three(ldir->file->fullpath, "/", elem->d_name);
		if (!fullpath || !(lst_elem = ft_lfile_new(fullpath, 0)))
		{
			closedir(dir);
			ft_lfile_del(lfile);
			return (ft_dir_error(2));
		}
		ft_lfile_push(&lfile, lst_elem);
	}
	closedir(dir);
	return (lfile);
}

//La fonciton recursive
int			ft_print_dir(t_lfile *dir, unsigned char flag)
{
	t_lfile		*lfile;
	t_file		*file;
	int			ret;

	if (!(lfile = ft_getfile(dir)))
		return (0);
	ft_lfile_sort(&lfile, flag);
	if (flag & FIRST)
		flag ^= FIRST;
	else
		ft_putendl("");
	if (flag & SEVERAL)
		ft_printf("%s:\n", dir->name);
	if (flag & LONG)
		ft_print_dir_total(lfile);
	ft_print_lfile(lfile, flag);
	if (flag & REC)
	{
		while (lfile != NULL)
		{
			file = lfile->file;
			if (S_ISDIR(file->mode) && ft_strcmp(file->name, ".") &&
				ft_strcmp(file->name, ".."))
			{
				if(!(ret = ft_print_dir(lfile, flag)))
					return (0);
			}
			file = file->next;
		}
	}
	return (1);
}
