/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_uid_gid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/25 11:01:35 by gly               #+#    #+#             */
/*   Updated: 2019/04/25 12:15:26 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pwd.h>
#include <grp.h>
#include "ft_ls.h"
#include "libft/incl/libft.h"

int		ft_set_uid_gid(t_file *elem, struct stat statbuf)
{
	struct passwd	*pwd;
	struct group	*grp;

	pwd = getpwuid(statbuf.st_uid);
	if (pwd == NULL)
		elem->uid = ft_itoa(statbuf.st_uid);
	else
		elem->uid = ft_strdup(pwd->pw_name);
	grp = getgrgid(statbuf.st_gid);
	if (grp == NULL)
		elem->gid = ft_itoa(statbuf.st_uid);
	else
		elem->gid = ft_strdup(grp->gr_name);
	return (elem->uid == NULL || elem->uid == NULL ? 0 : 1);
}
