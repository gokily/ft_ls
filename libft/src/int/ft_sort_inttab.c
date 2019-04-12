/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_inttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/11 12:00:44 by gly               #+#    #+#             */
/*   Updated: 2019/01/11 16:21:55 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		*ft_sort_inttab(int *tab, int n)
{
	int i;
	int	tmp;
	int flag;
	int	*sorted;

	flag = 0;
	sorted = tab;
	while (flag == 0)
	{
		i = 0;
		flag = 1;
		while (i < n - 1)
		{
			if (sorted[i] > sorted[i + 1])
			{
				tmp = sorted[i];
				sorted[i] = sorted[i + 1];
				sorted[i + 1] = tmp;
				flag = 0;
			}
			i++;
		}
	}
	tab = sorted;
	return (tab);
}
