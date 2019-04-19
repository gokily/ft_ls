/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 14:52:35 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 13:58:27 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			ft_print_lfile(t_lfile *file, unsigned int flag)
{
	if (file == NULL)
		return (1);
	if (flag & LNG)
		ft_print_lfile_long(file, flag);
	else
		ft_print_lfile_short(file, flag);
	return (1);
}
