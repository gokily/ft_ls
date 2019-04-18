/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_t_ls_manipulators.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 10:31:01 by gly               #+#    #+#             */
/*   Updated: 2019/04/18 10:31:51 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_ls	*ft_t_ls_new(void)
{
	t_ls	*ls;

	if (!(ls = malloc(sizeof(t_ls))))
		return (NULL);
	ls->nbdir = 0;
	ls->flag = FIRST | COLUMN;
	ls->ldir = NULL;
	ls->status = 0;
	return (ls);
}
