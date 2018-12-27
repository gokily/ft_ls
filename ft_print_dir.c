#include "ft_ls.h"

static void		ft_print_dir_total(t_lfile *file)
{
	unsigned int	size;

	size = 0;
	while (file)
	{
		size += file->blkcnt;
		file = file->next;
	}
	ft_printf("total %u\n", size);
	return ;
}

static t_lfile	*ft_getfile(t_lfile *ldir)
{
	DIR				*dir;
	struct dirent	*elem;
	char			*fullpath;
	t_lfile			*lst_elem;
	t_lfile			*file;

	file = NULL;
	if (!(dir = opendir(ldir->fullpath)))
		return (ft_dir_error(1));

	while ((elem = readdir(dir)))
	{
		if (!(fullpath = ft_strjoin_three(ldir->fullpath, "/", elem->d_name)) ||
			!(lst_elem = ft_lfile_new(fullpath, 0)))
		{
			closedir(dir);
			ft_lfile_del(file);
			return (ft_dir_error(2));
		}
		ft_lfile_push(&file, lst_elem);
	}
	closedir(dir);
	return (file);
}

//La fonciton recursive
int			ft_print_dir(t_lfile *ldir, unsigned char flag)
{
	t_lfile		*file;
	int			ret;

	if (!(file = ft_getfile(ldir)))//Recupere la liste des fichiers dans le repertoire
		return (0);
	ft_lfile_sort(&file, flag);
	if (flag & FIRST)
		flag ^= FIRST;
	else
		ft_putendl("");
	if (flag & SEVERAL)
		ft_printf("%s:\n", ldir->name);
	if (flag & LONG)
		ft_print_dir_total(file);
	ft_print_lfile(file, flag); //Imprime les fichiers dans le repertoire selon les flags
	if (flag & REC)
	{
		while (file != NULL)
		{
			if (S_ISDIR(file->mode) && ft_strcmp(file->name, ".") &&
				ft_strcmp(file->name, ".."))
			{
				if(!(ret = ft_print_dir(file, flag)))
					return (0);
			}
			file = file->next;
		}
	}
	return (1);
}
