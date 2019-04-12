/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:49:44 by gly               #+#    #+#             */
/*   Updated: 2019/03/14 10:24:07 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "ft_printf.h"

static int	ft_write_out(char *str, int len)
{
	write(1, str, len);
	return (0);
}

int			ft_add_to_buffer(char *str, int len)
{
	static char	buf[BUFFSIZE];
	static int	ret = 0;
	static int	i = 0;
	int			tmp;

	if (str == NULL)
	{
		write(1, buf, i);
		i = 0;
		tmp = ret;
		ret = 0;
		return (tmp);
	}
	if (i + len > BUFFSIZE)
		i = ft_write_out(buf, i);
	if (len > BUFFSIZE)
		write(1, str, len);
	else
	{
		ft_strncpy(buf + i, str, len);
		i += len;
	}
	ret += len;
	return (ret);
}
