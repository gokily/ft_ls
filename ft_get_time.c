/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:13:40 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 18:48:02 by gly              ###   ########.fr       */
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
	if (file_time > now_time || now_time - file_time > 60 * 60 * 24 * 180)
	{
		year_time = ft_strndup(time_str + 4, 7);
		year_time = ft_strjoinfree(year_time, ft_strrchr(time_str, ' '),
					LEFT);
		year_time[ft_strlen(year_time) - 1] = '\0';
		return (year_time);
	}
	else
		return (ft_strndup(time_str + 4, 12));
}
