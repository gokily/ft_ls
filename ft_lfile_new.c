/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:33:40 by gly               #+#    #+#             */
/*   Updated: 2019/04/23 16:34:31 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <grp.h>
#include <sys/xattr.h>
#include <sys/acl.h>
#include <pwd.h>
#include "libft/incl/libft.h"
#include "ft_ls.h"

static inline char	*ft_filename(const char *filepath, unsigned int flag)
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

static inline int	ft_fill_link(t_file *elem, struct stat statbuf)
{
	char	*link;

	elem->link = NULL;
	if (S_ISLNK(statbuf.st_mode))
	{
		if (!(link = ft_strnew(BUFFSIZE)))
			return (0);
		readlink(elem->fullpath, link, BUFFSIZE);
		lstat(link, &statbuf);
		if (S_ISDIR(statbuf.st_mode))
			elem->flag |= DIRLNK;
		elem->link = link;
	}
	return (1);
}

static inline int	ft_fill_file(t_file *elem, struct stat statbuf)
{
	acl_t	acl;

	elem->flag = 0;
	elem->mode = statbuf.st_mode;
	elem->nlink = statbuf.st_nlink;
	elem->size = statbuf.st_size;
	elem->blksize = statbuf.st_blksize;
	elem->blkcnt = statbuf.st_blocks;
	elem->uid = getpwuid(statbuf.st_uid)->pw_name;
	elem->gid = getgrgid(statbuf.st_gid)->gr_name;
	elem->atim = statbuf.st_atimespec;
	elem->mtim = statbuf.st_mtimespec;
	elem->rdev = statbuf.st_rdev;
	if (ft_fill_link(elem, statbuf) == 0)
		return (0);
	acl = NULL;
	acl = acl_get_link_np(elem->fullpath, ACL_TYPE_EXTENDED);
	elem->acl = acl == NULL ? 0 : 1;
	acl_free(acl);
	return (1);
}

t_lfile				*ft_lfile_new(char *filepath, unsigned int lsflag,
		unsigned int flag, t_ls *ls)
{
	t_lfile		*elem;
	struct stat	statbuf;
	char		namebuf[BUFFSIZE];
	t_file		*file;

	if (!(elem = malloc(sizeof(t_lfile))) ||
			!(file = malloc(sizeof(t_file))))
		return (NULL);
	elem->file = file;
	if (lstat(filepath, &statbuf) == -1)
	{
		ft_dir_error(filepath, ls);
		return (NULL);
	}
	if (!(file->name = ft_filename(filepath, lsflag)))
		return (NULL);
	file->fullpath = filepath;
	if (!(ft_fill_file(file, statbuf)))
		return (NULL);
	file->ext = listxattr(filepath, namebuf, BUFFSIZE, XATTR_NOFOLLOW) > 0
		? 1 : 0;
	ft_set_colors(file, &(file->col), flag);
	elem->next = NULL;
	return (elem);
}
