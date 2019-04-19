/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_colors.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 09:57:19 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 11:44:12 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_ls.h"

static inline void	ft_set_dir_col(t_file *file, char **col)
{
	if (file->mode & S_IWOTH && file->mode & S_ISVTX)
		*col = "\x1b[30;42m";
	else if (file->mode & S_IWOTH)
		*col = "\x1b[30;43m";
	else
		*col = "\x1b[36;1m";
}

static inline void	ft_set_exec_col(t_file *file, char **col)
{
	if (file->mode & S_ISUID)
		*col = "\x1b[30;41m";
	else if (file->mode & S_ISGID)
		*col = "\x1b[30;46m";
	else
		*col = "\x1b[31m";
}

int		ft_set_colors(t_file *file, char **col, unsigned int flag)
{
	*col = "";
	if (flag & COLOR)
	{
		if (S_ISLNK(file->mode))
			*col = "\x1b[35m";
		else if (S_ISSOCK(file->mode))
			*col = "\x1b[32m";
		else if (S_ISFIFO(file->mode))
			*col = "\x1b[33m";
		else if (S_ISBLK(file->mode))
			*col = "\x1b[34;46m";
		else if (S_ISCHR(file->mode))
			*col = "\x1b[34;43m";
		else if (S_ISDIR(file->mode))
			ft_set_dir_col(file, col);
		else if (file->mode & S_IXUSR)
			ft_set_exec_col(file, col);
	}
	return (1);
}



