/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_manipulators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:06:43 by gly               #+#    #+#             */
/*   Updated: 2019/02/22 16:46:59 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>

char	*ft_filename(const char *filepath, unsigned char flag)
{
	char	*name;
	char	*slash;

	if (flag == LSARG)
	{
		if (!(name = ft_strdup(filepath)))
			return (NULL);
	}
	else 
	{
		slash = ft_strrchr(filepath, '/');
		if (!(name = ft_strdup(slash != NULL ? slash + 1 : filepath)))
			return (NULL);
	}
	return (name);
}

void	ft_fill_file(t_file *elem, struct stat statbuf)
{
	elem->mode = statbuf.st_mode;
	elem->nlink = statbuf.st_nlink;
	elem->size = statbuf.st_size;
	elem->blksize = statbuf.st_blksize;
	elem->blkcnt = statbuf.st_blocks;
	elem->uid = getpwuid(statbuf.st_uid)->pw_name;
	elem->gid = getgrgid(statbuf.st_gid)->gr_name;
	elem->atim = statbuf.st_atimespec;
	elem->mtim = statbuf.st_mtimespec;
	elem->ctim = statbuf.st_ctimespec;
}

t_lfile	*ft_lfile_new(char *filepath, unsigned char flag)
{
	t_lfile		*elem;
	struct stat	statbuf;
	char		*name;
	t_file		*file;

	if (!(elem = malloc(sizeof(t_lfile))))
		return (NULL);
	lstat(filepath, &statbuf);//comment traiter les erreurs de file (acces ou autre)?
	if (!(name = ft_filename(filepath, flag)))
	{
		free(elem);
		return (NULL);
	}
	if (!(file = malloc(sizeof(t_file))))
		return (NULL);
	elem->file = file;
	file->name = name;
	file->fullpath = filepath;
	ft_fill_file(file, statbuf);
	elem->next = NULL;
	return (elem);
}

void	ft_lfile_push(t_lfile **lst, t_lfile *elem)
{
	t_lfile	*tmp;

	if (elem == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = elem;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return ;
}

void	ft_lfile_delall(t_lfile *lfile)
{
	t_lfile		*elem;
	t_file		*file;

	elem = lfile;
	while (elem != NULL)
	{
		elem = lfile->next;
		file = lfile->file;
		free(file->name);
		free(file->fullpath);
		free(file);
		free(lfile);
	}	
}
