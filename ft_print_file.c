#include "ft_ls.h"

static void	ft_print_file(t_file *file, unsigned char flag)
{
	if (flag & LONG)
		ft_print_file_long(file, flag);
	else
		ft_print_file_short(file);
}

// need to change the location of function in the c files.
void		ft_print_lfile(t_lfile *file, unsigned char flag)
{
	while (file != NULL)
	{
		// something is false here the conditions.
		if (!(flag & ALL) &&
			ft_strcmp(file->file->name, ".") && ft_strcmp(file->file->name, ".."))
				ft_print_file(file->file, flag);
		else
			ft_print_file(file->file, flag);
		file = file->next;
	}
	return ;
}
