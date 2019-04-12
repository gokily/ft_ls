/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_comparators.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:27:56 by gly               #+#    #+#             */
/*   Updated: 2019/02/21 11:28:31 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_int_is_bigger(int first, int second)
{
	return (first > second ? 1 : 0);
}

int		ft_int_is_smaller(int first, int second)
{
	return (first < second ? 1 : 0);
}
