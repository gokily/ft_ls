/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/22 13:13:40 by gly               #+#    #+#             */
/*   Updated: 2019/02/22 14:40:48 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


char	*ft_time_year(time_t file_time, char **month)
{
	struct tm	*elem;
	char		*time_str;

	elem = localtime(&file_time);
	time_str = ft_strdup(month[elem->tm_mon]);
	time_str = ft_strjoinfree(time_str, " ", LEFT);
	time_str = ft_strjoinfree(time_str, ft_itoa(elem->tm_mday), LEFT);
	time_str = ft_strjoinfree(time_str, "  ", LEFT);
	time_str = ft_strjoinfree(time_str, ft_itoa(elem->tm_year + 1900),
			LEFT | RIGHT);
	return (time_str);
}

char	*ft_time_hour(time_t file_time, char **month)
{
	struct tm	*elem;
	char		*time_str;

	elem = localtime(&file_time);
	time_str = ft_strdup(month[elem->tm_mon]);
	time_str = ft_strjoinfree(time_str, elem->tm_mday > 9 ? " " : "  ", LEFT);
	time_str = ft_strjoinfree(time_str, ft_itoa(elem->tm_mday), LEFT);
	time_str = ft_strjoinfree(time_str, elem->tm_hour > 9 ? " " : " 0", LEFT);
	time_str = ft_strjoinfree(time_str, ft_itoa(elem->tm_hour),
			LEFT | RIGHT);
	time_str = ft_strjoinfree(time_str, elem->tm_min > 9 ? ":" : ":0", LEFT);
	time_str = ft_strjoinfree(time_str, ft_itoa(elem->tm_min),
			LEFT | RIGHT);
	return (time_str);
}

char	*ft_get_time(struct timespec file_timespec)
{
	time_t		now_time;
	time_t		file_time;
	char		*month[12];

	file_time = file_timespec.tv_sec;
	now_time = time(NULL);
	month[0] = "Jan";
	month[1] = "Feb";
	month[2] = "Mar";
	month[3] = "Apr";
	month[4] = "May";
	month[5] = "Jun";
	month[6] = "Jul";
	month[7] = "Aug";
	month[8] = "Sep";
	month[9] = "Oct";
	month[10] = "Nov";
	month[11] = "Dec";
	if (now_time - file_time > 60 * 60 * 24 * 180)
		return (ft_time_year(file_time, month));
	else
		return (ft_time_hour(file_time, month));
	return ("test");
}
