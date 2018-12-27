#include "ft_ls.h"

char	*ft_filename(const char *filepath, unsigned char flag)
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
void	ft_fill_lfile(t_lfile *elem, struct stat statbuf)
{
	elem->mode = statbuf.st_mode;
	elem->nlink = statbuf.st_nlink;
	elem->size = statbuf.st_size;
	elem->blksize = statbuf.st_blksize;
	elem->blkcnt = statbuf.st_blocks;
	elem->uid = statbuf.st_uid;
	elem->gid = statbuf.st_gid;
	elem->atim = statbuf.st_atim;
	elem->mtim = statbuf.st_mtim;
	elem->ctim = statbuf.st_ctim;
}

t_lfile	*ft_lfile_new(char *filepath, unsigned char flag)
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
	if (!(name = ft_filename(filepath, flag)))
	{
		free(elem);
		return (NULL);
	}
	elem->name = name;
	elem->fullpath = filepath;
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

void	ft_lfile_del(t_lfile *file)
{
	t_lfile		*elem;

	elem = file;
	while (elem != NULL)
	{
		elem = file->next;
		free(file->name);
		free(file->fullpath);
		free(file);
	}	
}