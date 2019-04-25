/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calculate_space.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 14:07:33 by gly               #+#    #+#             */
/*   Updated: 2019/04/25 11:47:37 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include "libft/incl/libft.h"
#include "ft_ls.h"

static inline int		ft_calculate_space_one(t_lfile *file)
{
	int		n;
	int		tmp;

	n = 0;
	while (file != NULL)
	{
		tmp = ft_ulllen_base(file->file->nlink, 10);
		n = n > tmp ? n : tmp;
		file = file->next;
	}
	return (n);
}

static inline int		ft_calculate_space_two(t_lfile *file)
{
	int		n;
	int		tmp;

	n = 0;
	while (file != NULL)
	{
		tmp = ft_strlen(file->file->uid);
		n = n > tmp ? n : tmp;
		file = file->next;
	}
	return (n);
}

static inline int		ft_calculate_space_three(t_lfile *file)
{
	int		n;
	int		tmp;

	n = 0;
	while (file != NULL)
	{
		tmp = ft_strlen(file->file->gid);
		n = n > tmp ? n : tmp;
		file = file->next;
	}
	return (n);
}

static inline t_space	ft_calculate_space_four(t_lfile *file, t_space space)
{
	int		n;
	int		tmp;

	n = 0;
	space.f_a = 0;
	space.f_b = 0;
	while (file != NULL)
	{
		if (S_ISCHR(file->file->mode) || S_ISBLK(file->file->mode))
		{
			space.f_a = space.f_a
				> (int)ft_ulllen_base(major(file->file->rdev), 10)
				? space.f_a : (int)ft_ulllen_base(major(file->file->rdev), 10);
			space.f_b = space.f_b
				> (int)ft_ulllen_base(minor(file->file->rdev), 10)
				? space.f_b : (int)ft_ulllen_base(minor(file->file->rdev), 10);
		}
		tmp = ft_ulllen_base(file->file->size, 10);
		n = n > tmp ? n : tmp;
		file = file->next;
	}
	space.f_c = space.f_a != 0 && space.f_b != 0
		&& space.f_a + space.f_b + 2 > n
		? space.f_a + space.f_b + 2 : n;
	return (space);
}

t_space					ft_calculate_space(t_lfile *file)
{
	t_space	space;

	space.one = ft_calculate_space_one(file);
	space.two = ft_calculate_space_two(file);
	space.three = ft_calculate_space_three(file);
	space = ft_calculate_space_four(file, space);
	return (space);
}
