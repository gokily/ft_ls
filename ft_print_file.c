/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:52:35 by gly               #+#    #+#             */
/*   Updated: 2019/02/22 14:53:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	ft_print_file(t_file *file, unsigned char flag)
{
	if (flag & LONG)
		return (ft_print_file_long(file, flag));
	else
		return (ft_print_file_short(file));
}

// need to change the location of function in the c files.
int			ft_print_lfile(t_lfile *file, unsigned char flag)
{
	while (file != NULL)
	{
		if ((flag & ALL) || file->file->name[0] != '.')
		{
			if (!(ft_print_file(file->file, flag)))
				return (0);
		}
		file = file->next;
	}
	return (1);
}
