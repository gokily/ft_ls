/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 08:33:37 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 16:57:04 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include <unistd.h>

int		ft_printstr(char *str)
{
	int		len;

	len = ft_strlen(str);
	write(1, str, len);
	return (len);
}

int		ft_printf2(const char *format, va_list ap)
{
	int		i;

	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i = ft_add_conv(format, ap, i + 1);
		}
		else
			i = ft_add_str(format, i);
	}
	return (ft_add_to_buffer(NULL, 0, -1));
}

int		ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (-1);
	if (ft_strchr(format, '%') == NULL)
		return (ft_printstr((char *)format));
	ft_add_to_buffer(NULL, 0, STDOUT_FILENO);
	va_start(ap, format);
	ret = ft_printf2(format, ap);
	va_end(ap);
	return (ret);
}

int		ft_dprintf(int fd, const char *format, ...)
{
	va_list	ap;
	int		ret;

	if (format == NULL)
		return (-1);
	if (ft_strchr(format, '%') == NULL)
	{
		ret = ft_strlen(format);
		write(fd, format, ret);
		return (ret);
	}
	ft_add_to_buffer(NULL, 0, fd);
	va_start(ap, format);
	ret = ft_printf2(format, ap);
	va_end(ap);
	return (ret);
}
