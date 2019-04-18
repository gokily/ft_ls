/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_to_buffer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:49:44 by gly               #+#    #+#             */
/*   Updated: 2019/04/18 13:51:15 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <string.h>
#include "libft.h"
#include "ft_printf.h"

static inline int	ft_write_out(char *str, int len, int fd)
{
	write(fd, str, len);
	return (0);
}

static inline int	ft_last_write(char *str, int *i, int *ret, int *fd)
{
	int		tmp;

	write(*fd, str, *i);
	*i = 0;
	tmp = *ret;
	*ret = 0;
	*fd = -1;
	return (tmp);
}

int					ft_add_to_buffer(char *str, int len, int fd)
{
	static char	buf[BUFFSIZE];
	static int	ret = 0;
	static int	i = 0;
	static int	f = -1;

	if (f == -1)
	{
		f = fd;
		return (0);
	}
	if (str == NULL)
		return (ft_last_write(buf, &i, &ret, &f));
	if (i + len > BUFFSIZE)
		i = ft_write_out(buf, i, f);
	if (len > BUFFSIZE)
		write(f, str, len);
	else
	{
		ft_strncpy(buf + i, str, len);
		i += len;
	}
	ret += len;
	return (ret);
}
