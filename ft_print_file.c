/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:52:35 by gly               #+#    #+#             */
/*   Updated: 2019/03/08 15:39:29 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_print_file(t_file *file, unsigned char flag, t_space space)
{
	if (flag & LONG)
		return (ft_print_file_long(file, flag, space));
	else
		return (ft_print_file_short(file));
}

t_space		ft_calculate_space(t_lfile *file, unsigned char flag)
{
	int	n;
	int	tmp;
	t_space			space;
	t_lfile	*elem;

	elem = file;
	space.four_a = 0;
	space.four_b = 0;
	n = 0;
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			tmp = ft_ulllen_base(file->file->nlink, 10);
			n = n > tmp ? n : tmp; 
		}
		file = file->next;
	}
	space.one = n;

	n = 0;
	file = elem;
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			tmp = ft_strlen(file->file->uid);
			n = n > tmp ? n : tmp; 
		}
		file = file->next;
	}
	space.two = n;

	n = 0;
	file = elem;
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			tmp = ft_strlen(file->file->gid);
			n = n > tmp ? n : tmp; 
		}
		file = file->next;
	}
	space.three = n;

	n = 0;
	file = elem;
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			if (S_ISCHR(file->file->mode) || S_ISBLK(file->file->mode))
			{
				space.four_a = space.four_a >
					(int)ft_ulllen_base(major(file->file->rdev), 10) ?
					space.four_a : (int)ft_ulllen_base(major(file->file->rdev), 10);
				space.four_b = space.four_b >
					(int)ft_ulllen_base(minor(file->file->rdev), 10) ?
					space.four_b : (int)ft_ulllen_base(minor(file->file->rdev), 10);
			}
			tmp = ft_ulllen_base(file->file->size, 10);
			n = n > tmp ? n : tmp; 
		}
		file = file->next;
	}
	space.four_c = space.four_a + space.four_b + 2 > n ?
		space.four_a + space.four_b + 2 : n;
	return (space);
}



// need to change the location of function in the c files.
int			ft_print_lfile(t_lfile *file, unsigned char flag)
{
	t_space		space;
		
	space = ft_calculate_space(file, flag);
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			if (!(ft_print_file(file->file, flag, space)))
				return (0);
		}
		file = file->next;
	}
	return (1);
}
