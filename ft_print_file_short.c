/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file_short.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 16:38:39 by gly               #+#    #+#             */
/*   Updated: 2019/04/01 14:37:30 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/ioctl.h>
#include <unistd.h>

int		ft_get_window_size(void)
{
	struct winsize w;

	ioctl(STDOUT_FILENO, TIOCGSIZE, &w);
	return (w.ws_col);
}

t_linfo		ft_get_lfile_info(t_lfile *file)
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
	return (linfo);
}

int		ft_print_lfile_short(t_lfile *file)
{
	int		ncol;
	int		nrow;
	int		i;
	int		j;
	int		k;
	t_linfo	linfo;
	t_lfile	*head;

	linfo = ft_get_lfile_info(file);
	ncol = ft_get_window_size() / (linfo.maxl + 1);
	nrow = linfo.nb / ncol + (linfo.nb % ncol ? 1 : 0);
	head = file;
	k = 0;
	while (k < nrow)
	{
		file = head;
		i = 1;
		while (i <= ncol)
		{
			j = 0;
				printf("%s%-*s" COLRESET, file->file->col, linfo.maxl + 1,
						file->file->name);
			while (j < nrow)
			{
				file = file->next;
				if (file == NULL)
				{
					j = nrow;
					i = ncol + 1;
				}
				j++;
			}
			i++;
		}
		printf("\n");
		head = head->next;
		k++;
	}
	return (1);
}
