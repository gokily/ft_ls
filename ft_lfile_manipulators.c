/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_manipulators.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:06:43 by gly               #+#    #+#             */
/*   Updated: 2019/04/16 11:59:25 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>

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

t_file	*ft_set_col(t_file *elem)
{
	if (S_ISDIR(elem->mode))
		elem->col = ft_strdup(COL_CYAN);
	else if (S_ISLNK(elem->mode))
		elem->col = ft_strdup(COL_MAGENTA);
	else if (S_ISBLK(elem->mode))
		elem->col = ft_strdup(COL_BLUE BG_CYAN);
	else if (S_ISCHR(elem->mode))
		elem->col = ft_strdup(COL_BLUE BG_YELLOW);
	else if (elem->mode & S_IXUSR)
		elem->col = ft_strdup(COL_RED);
	else
		elem->col = ft_strdup(COLRESET);
	if (elem->col == NULL)
		return (NULL);
	else
		return (elem);
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
	elem->rdev = statbuf.st_rdev;
	elem->link = NULL;
}

t_lfile	*ft_lfile_new(char *filepath, unsigned char flag)
{
	t_lfile		*elem;
	struct stat	statbuf;
	t_file		*file;
	char		*link;
	char		namebuf[BUFFSIZE];
	acl_t acl;
	//	acl_entry_t dummy;

	if (!(elem = malloc(sizeof(t_lfile))) || !(file = malloc(sizeof(t_file))))
		return (NULL);
	elem->file = file;
	if (lstat(filepath, &statbuf) == -1)
	{
		ft_dir_error(filepath);
		return (NULL);
	}
	if (!(file->name = ft_filename(filepath, flag)))
	{
		free(elem);
		return (NULL);
	}
	file->ext = listxattr(filepath, namebuf, BUFFSIZE, 0) > 0 ? 1 : 0;
	acl = NULL;
	acl = acl_get_link_np(filepath, ACL_TYPE_EXTENDED);
	file->acl = acl == NULL ? 0 : 1;
	acl_free(acl);
	file->fullpath = filepath;
	ft_fill_file(file, statbuf);
	ft_set_col(file);
	if (S_ISLNK(statbuf.st_mode))
	{
		if (!(link = ft_strnew(BUFFSIZE)))
			return (NULL);
		readlink(filepath, link, BUFFSIZE);
		file->link = link;
	}
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

void	ft_freenull(void *tmp)
{
	free(tmp);
	tmp = NULL;
}

void	ft_lfile_delall(t_lfile *lfile)
{
	t_lfile		*elem;
	t_file		*file;

	elem = lfile;
	while (elem != NULL)
	{
		lfile = elem;
		elem = elem->next;			
		file = lfile->file;
		ft_freenull(file->name);
		ft_freenull(file->fullpath);
		ft_freenull(file->link);
		ft_freenull(file->col);
		ft_freenull(file);
		ft_freenull(lfile);
	}	
}
