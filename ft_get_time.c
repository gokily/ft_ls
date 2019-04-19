/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:13:40 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 15:00:41 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft/incl/libft.h"
#include "ft_ls.h"

char	*ft_get_time(struct timespec file_timespec)
{
	time_t		now_time;
	time_t		file_time;
	char		*time_str;
	char		*year_time;

	file_time = file_timespec.tv_sec;
	now_time = time(NULL);
	time_str = ctime(&file_time);
	if (now_time - file_time > 60 * 60 * 24 * 180)
	{
		year_time = ft_strjoinfree(ft_strndup(time_str + 4, 7), " ", LEFT);
		return (ft_strjoinfree(year_time, ft_strndup(time_str + 20, 4),
					LEFT | RIGHT));
	}
	else
		return (ft_strndup(time_str + 4, 12));
}
