/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lfile_sort_functions.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/19 12:17:31 by gly               #+#    #+#             */
/*   Updated: 2019/04/23 16:31:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/incl/libft.h"
#include "ft_ls.h"

int	ft_compare_mtim(t_file *current, t_file *next)
{
	if (current->mtim.tv_sec < next->mtim.tv_sec)
		return (1);
	else
		return (0);
}

int	ft_compare_atim(t_file *current, t_file *next)
{
	if (current->atim.tv_sec < next->atim.tv_sec)
		return (1);
	else
		return (0);
}

int	ft_compare_name(t_file *current, t_file *next)
{
	return (ft_strcmp(current->name, next->name));
}

int	ft_is_dir(t_file *current, t_file *next)
{
	int		first;
	int		second;

	if (S_ISDIR(current->mode) || current->flag & DIRLNK)
		first = 1;
	else
		first = 0;
	if (S_ISDIR(next->mode) || next->flag & DIRLNK)
		second = 1;
	else
		second = 0;
	return (first - second);
}
