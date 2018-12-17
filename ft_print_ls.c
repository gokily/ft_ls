#include "ft_ls.h"

t_lfile	*ft_getfile(t_lfile *ldir)
{
	DIR				*dir;
	struct dirent	*elem;
	char			*fullpath;
	t_lfile			*lst_elem;
	t_lfile			*file;

	*file = NULL;
	dir = opendir(ldir->name);
	while ((elem = readdir(dir)))
	{
		if (!(fullpath = ft_strjoin_all(ldir->fullpath, "/", elem->d_name)))
			return (NULL);
		lst_elem = ft_lfile_new(fullpath, NULL);
		ft_lfile_push(&file, lst_elem);
	}
	n = closedir(dir);
	return (file);
}

void	ft_print_lfile(t_lfile *file, unsigned char *flag)
{
	while (file != NULL)
	{
		
	}
}

//La fonciton recursive
void	ft_print_dir(t_lfile *ldir, unsigned char flag)
{
	t_lfile		*file;

	file = ft_getfile(ldir); //Recupere la liste des fichiers dans le repertoire
	ft_lfile_sort(&file, flag);
	if (flag & FIRST)
		flag ^= FIRST;
	else
		ft_putendl("");
	if (flag & SEVERAL)
		ft_printf("%s:\n", ldir->name);
	ft_print_lfile(file, flag); //Imprime les fichiers dans le repertoire selon les flags
	if (flag & REC)
	{
		while (file != NULL)
		{
			if (S_ISDIR(file->mode) && ft_strcmp(file->name, ".") &&
				ft_strcmp(file->name, ".."))
				ft_print_dir(file, flag);
			file = file->next;
		}
	}
	return ;
}

//La fonction qui va appeler les differents repertoires appeles par ls.
void	ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;
	t_lfile	*file;

	ldir = ls->ldir;
	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	while (ldir != NULL)
	{
		ft_print_dir(ldir, ls->flag);
		ldir = ldir->next;
	}
	return ;
}