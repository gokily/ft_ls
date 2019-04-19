/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:33:40 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 18:49:46 by gly              ###   ########.fr       */
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

static inline int	ft_fill_file(t_file *elem, struct stat statbuf)
{
	acl_t	acl;
	char	*link;

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
	elem->link = NULL;
	if (S_ISLNK(statbuf.st_mode))
	{
		if (!(link = ft_strnew(BUFFSIZE)))
			return (0);
		readlink(elem->fullpath, link, BUFFSIZE);
		elem->link = link;
	}
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
	{
		free(elem);
		return (NULL);
	}
	file->fullpath = filepath;
	if (!(ft_fill_file(file, statbuf)))
		return (NULL);
	file->ext = listxattr(filepath, namebuf, BUFFSIZE, 0) > 0 ? 1 : 0;
	ft_set_colors(file, &(file->col), flag);
	elem->next = NULL;
	return (elem);
}
