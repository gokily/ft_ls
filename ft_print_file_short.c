/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:38:39 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 11:59:00 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <unistd.h>

static inline int		ft_get_window_size(void)
{
	struct winsize w;

	ioctl(STDIN_FILENO, TIOCGSIZE, &w);
	return (w.ws_col);
}

static inline t_linfo	ft_get_lfile_info(t_lfile *file)
{
	int		maxl;
	int		n;
	int		nb;
	t_linfo	linfo;

	maxl = 0;
	nb = 0;
	while (file != NULL)
	{
		n = ft_strlen(file->file->name);
		maxl = n > maxl ? n : maxl;
		nb++;
		file = file->next;
	}
	linfo.nb = nb;
	linfo.maxl = maxl;
	linfo.ncol = ft_get_window_size() / (maxl + 1);
	linfo.nrow = nb / linfo.ncol + (nb % linfo.ncol ? 1 : 0);
	linfo.i = 0;
	linfo.j = 0;
	linfo.k = 0;
	return (linfo);
}

static inline void		ft_print_lfile_columns(t_lfile *file, t_linfo linfo,
		unsigned int flag)
{
	t_lfile	*tmp;

	while (linfo.i++ < linfo.nrow)
	{
		tmp = file;
		linfo.j = 1;
		while (linfo.j++ <= linfo.ncol)
		{
			linfo.k = 0;
			ft_printf("%s%s%s%*s", tmp->file->col, tmp->file->name,
					flag ? COLRESET : "",
					linfo.maxl + 1 - ft_strlen(tmp->file->name), " ");
			while (linfo.k++ < linfo.nrow)
			{
				tmp = tmp->next;
				if (tmp == NULL)
				{
					linfo.k = linfo.nrow;
					linfo.j = linfo.ncol + 1;
				}
			}
		}
		ft_printf("%c", '\n');
		file = file->next;
	}
}

int						ft_print_lfile_short(t_lfile *file, unsigned int flag)
{
	if (flag & COLUMN)
		ft_print_lfile_columns(file, ft_get_lfile_info(file), flag & COLOR);
	else
	{
		if (flag & COLOR)
		{
			while (file != NULL)
			{
				ft_printf("%s%s%s\n", file->file->col, file->file->name,
						COLRESET);
				file = file->next;
			}
		}
		else
		{
			while (file != NULL)
			{
				ft_putendl(file->file->name);
				file = file->next;
			}
		}
	}
	return (1);
}
