/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dir_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:44:35 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 12:10:30 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "libft/incl/libft.h"

int		ft_dir_error(char *file)
{
	char	*message;

	if (!(message = ft_strjoin("ls: ", file)))
	{
		exit(EXIT_FAILURE);
	}
	perror(message);
	free(message);
	return (0);
}
