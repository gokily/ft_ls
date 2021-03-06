/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:35 by gly               #+#    #+#             */
/*   Updated: 2019/04/23 15:32:23 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/incl/libft.h"
#include "ft_ls.h"

int		ft_dir_error(char *file, t_ls *ls)
{
	char	*message;

	if (ft_strlen(file) == 0)
	{
		perror("ls: fts_open");
		free(ls);
		exit(EXIT_FAILURE);
	}
	if (!(message = ft_strjoin("ls: ", file)))
		exit(EXIT_FAILURE);
	ls->status = 1;
	perror(message);
	free(message);
	return (1);
}
