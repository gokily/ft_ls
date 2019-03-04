/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_long.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:48:59 by gly               #+#    #+#             */
/*   Updated: 2019/03/04 16:31:57 by gly              ###   ########.fr       */
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

	perms = ft_lsperms(file->mode);
	(void)flag;
	if (!(time_str = ft_get_time(file->mtim)))
		return (0);
	printf("%s  ", perms);
	printf("%*u ", space.one, (unsigned int)file->nlink);
	printf("%-*s  %-*s  ", space.two, file->uid, space.three, file->gid);
	printf("%*u ", space.four, (unsigned int)file->size);
	printf("%s %s\n", time_str, file->name);
	free(time_str);
	return (1);
}
