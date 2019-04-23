/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_dir_arg.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 14:59:25 by gly               #+#    #+#             */
/*   Updated: 2019/04/23 15:06:02 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/incl/libft.h"

void	ft_sort_dir_arg(char **av, int i, int ac)
{
	int		n;
	int		flag;
	char	*tmp;

	flag = 0;
	while (flag == 0)
	{
		n = i;
		flag = 1;
		while (n < ac - 1)
		{
			if (ft_strcmp(av[n], av[n + 1]) > 0)
			{
				tmp = av[n];
				av[n] = av[n + 1];
				av[n + 1] = tmp;
				flag = 0;
			}
			n++;
		}
	}
}
