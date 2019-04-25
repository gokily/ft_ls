/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:48:59 by gly               #+#    #+#             */
/*   Updated: 2019/04/25 11:48:29 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <stdlib.h>
#include "libft/incl/libft.h"
#include "libft/incl/ft_printf.h"
#include "ft_ls.h"

static inline int	filetypeletter(int mode)
{
	char	c;

	if (S_ISREG(mode))
		c = '-';
	else if (S_ISDIR(mode))
		c = 'd';
	else if (S_ISBLK(mode))
		c = 'b';
	else if (S_ISCHR(mode))
		c = 'c';
	else if (S_ISFIFO(mode))
		c = 'p';
	else if (S_ISLNK(mode))
		c = 'l';
	else if (S_ISSOCK(mode))
		c = 's';
	else
		c = '?';
	return (c);
}

static inline char	*ft_lsperms(int mode)
{
	static const char	*rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	char				*perms;

	if (!(perms = ft_strnew(10)))
		return (NULL);
	perms[0] = filetypeletter(mode);
	ft_strcpy(&perms[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&perms[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&perms[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		perms[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		perms[6] = (mode & S_IXGRP) ? 's' : 'S';
	if (mode & S_ISVTX)
		perms[9] = (mode & S_IXOTH) ? 't' : 'T';
	return (perms);
}

static inline char	ft_get_ext(t_file *file)
{
	char ext;

	if (file->ext == 1)
		ext = '@';
	else if (file->acl == 1)
		ext = '+';
	else
		ext = ' ';
	return (ext);
}

static inline int	ft_print_file_long(t_file *file, unsigned int flag,
		t_space space)
{
	char	*perms;
	char	*time_str;
	char	ext;

	perms = ft_lsperms(file->mode);
	if (!(time_str = ft_get_time(file->mtim)))
		return (0);
	ext = ft_get_ext(file);
	ft_printf("%s%c %*u %-*s  %-*s  ", perms, ext, space.one, file->nlink,
			space.two, file->uid, space.three, file->gid);
	if (S_ISCHR(file->mode) || S_ISBLK(file->mode))
		ft_printf("%*u, %*u ", space.f_c - space.f_b - 2,
				major(file->rdev), space.f_b, minor(file->rdev));
	else
		ft_printf("%*u ", space.f_c, file->size);
	ft_printf("%s %s%s%s", time_str, flag & COLOR ? file->col : "",
			file->name, flag & COLOR ? COLRESET : "");
	if (S_ISLNK(file->mode))
		ft_printf(" -> %s", file->link);
	ft_printf("%c", '\n');
	free(perms);
	free(time_str);
	return (1);
}

int					ft_print_lfile_long(t_lfile *file, unsigned int flag)
{
	t_space	space;

	space = ft_calculate_space(file);
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			if (!(ft_print_file_long(file->file, flag, space)))
				return (0);
		}
		file = file->next;
	}
	return (1);
}
