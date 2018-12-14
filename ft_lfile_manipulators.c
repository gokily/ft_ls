#include "ft_ls.h"

char	*ft_filepath(const char *filepath, unsigned char flag)
{
	char	*name;

	if (flag == LSARG)
	{
		if (!(name = ft_strdup(filepath)))
			return (NULL);
	}
	else 
	{
		name = ft_strrchr(filepath, '/');
		if (!(name = ft_strdup(name != NULL ? name + 1 : filepath)))
			return (NULL);
	}
	return (name);
}

t_lfile	*ft_lfile_new(const char *filepath, unsigned char flag)
{
	t_lfile		*elem;
	struct stat	statbuf;
	char		*name;

	if (!(elem = malloc(sizeof(t_lfile))))
		return (NULL);
	/*
	if (lstat(filepath, &statbuf) == -1)
	{
		ft_lstat_err(errno);
		return (NULL);
	}
	*/
	lstat(filepath, &statbuf);
	name = ft_filepath(filepath, flag);
	elem->name = name;
	elem->mode = statbuf.st_mode;
	elem->nlink = statbuf.st_nlink;
	elem->uid = statbuf.st_uid;
	elem->gid = statbuf.st_gid;
	elem->atim = statbuf.st_atim;
	elem->mtim = statbuf.st_mtim;
	elem->ctim = statbuf.st_ctim;
	elem->next = NULL;
	return (elem);
}

void	ft_lfile_push(t_lfile **lst, t_lfile *elem)
{
	t_lfile	*tmp;

	if (elem == NULL)
		return ;
	if (*lst == NULL)
	{
		*lst = elem;
		return ;
	}
	tmp = *lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = elem;
	return ;
}