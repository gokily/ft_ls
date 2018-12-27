#include "ft_ls.h"

static void	ft_print_file(t_lfile *file, unsigned char flag)
{
	if (flag & LONG)
		ft_print_file_long(file);
	else
		ft_print_file_short(file);
}

void		ft_print_lfile(t_lfile *file, unsigned char flag)
{
	while (file != NULL)
	{
		if (flag & ALL == 0 &&
			ft_strcmp(file->name, ".") && ft_strcmp(file->name, ".."))
				ft_print_file(file, flag);
		else
			ft_print_file(file, flag);
		file = file->next;
	}
	return ;
}
