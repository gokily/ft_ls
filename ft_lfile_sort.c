/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 16:18:29 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 12:17:25 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static inline void	ft_lfile_rev(t_lfile **lfile)
{
	t_lfile *head;
	t_lfile	*rest;

	head = *lfile;
	rest = head->next;
	if (rest != NULL)
	{
		*lfile = rest;
		ft_lfile_rev(lfile);
		head->next->next = head;
		head->next = NULL;
	}
}

static inline void	ft_lfile_sort2(t_lfile **lfile,
		int (*cmp)(t_file *, t_file *))
{
	t_lfile	*start;
	t_lfile	*current;
	t_file	*tmp;
	int		flag;

	start = *lfile;
	flag = 0;
	while (flag == 0)
	{
		current = start;
		flag = 1;
		while (current->next != NULL)
		{
			if (cmp(current->file, current->next->file) > 0)
			{
				tmp = current->file;
				current->file = current->next->file;
				current->next->file = tmp;
				flag = 0;
			}
			current = current->next;
		}
	}
	*lfile = start;
}

void				ft_lfile_sort(t_lfile **lfile, unsigned int flag)
{
	if (*lfile == NULL || (*lfile)->next == NULL)
		return ;
	ft_lfile_sort2(lfile, &ft_compare_name);
	if (flag & LDIR)
		ft_lfile_sort2(lfile, &ft_is_dir);
	if (flag & ATIM && flag & MTIM)
		ft_lfile_sort2(lfile, &ft_compare_atim);
	else if (flag & MTIM)
		ft_lfile_sort2(lfile, &ft_compare_mtim);
	if (flag & REV)
		ft_lfile_rev(lfile);
	return ;
}
