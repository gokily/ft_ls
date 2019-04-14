/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:48:59 by gly               #+#    #+#             */
/*   Updated: 2019/04/01 10:58:49 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int filetypeletter(int mode)
{
	char    c;

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
	return(c);
}

char    *ft_lsperms(int mode)
{
	static const char *rwx[] = {"---", "--x", "-w-", "-wx",
		"r--", "r-x", "rw-", "rwx"};
	char	*perms;

	if (!(perms = ft_strnew(10)))
		return (NULL);
	perms[0] = filetypeletter(mode);
	ft_strcpy(&perms[1], rwx[(mode >> 6) & 7]);
	ft_strcpy(&perms[4], rwx[(mode >> 3) & 7]);
	ft_strcpy(&perms[7], rwx[(mode & 7)]);
	if (mode & S_ISUID)
		perms[3] = (mode & S_IXUSR) ? 's' : 'S';
	if (mode & S_ISGID)
		perms[6] = (mode & S_IXGRP) ? 's' : 'l';
	if (mode & S_ISVTX)
		perms[9] = (mode & S_IXOTH) ? 't' : 'T';
	return(perms);
}

int		ft_print_file_long(t_file *file, unsigned char flag, t_space space)
{
	char	*perms;
	char	*time_str;
	char	ext;

	perms = ft_lsperms(file->mode);
	(void)flag;
	if (file->ext == 1)
		ext = '@';
	else if (file->acl == 1)
		ext = '+';
	else
		ext = ' ';
	if (!(time_str = ft_get_time(file->mtim)))
		return (0);
	ft_printf("%s%c ", perms, ext);
	ft_printf("%*u ", space.one, (unsigned int)file->nlink);
	ft_printf("%-*s  %-*s  ", space.two, file->uid, space.three, file->gid);
	if (S_ISCHR(file->mode) || S_ISBLK(file->mode))
	{
		ft_printf("%*u, %*u ", space.four_c - space.four_b - 2,
				(unsigned int)major(file->rdev), space.four_b,
				(unsigned int)minor(file->rdev));
	}
	else
		ft_printf("%*u ", space.four_c, (unsigned int)file->size);
	ft_printf("%s %s%s" COLRESET, time_str, file->col, file->name);
	if (S_ISLNK(file->mode))
		ft_printf(" -> %s", file->link);
	ft_printf("\n");
	free(time_str);
	return (1);
}

int		ft_print_lfile_long(t_lfile *file, unsigned char flag)
{
	t_space	space;

	space = ft_calculate_space(file, flag);
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

