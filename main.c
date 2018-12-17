#include "ft_ls.h"

#include <stdio.h>

int		main(int ac, char **av)
{
	DIR	*tmp;
	int	n;
	struct dirent	*elem;
	t_ls		*ls;

	tmp = opendir(".");
	while ((elem = readdir(tmp)))
	{
		printf("%s", elem->d_name);
		if (elem->d_type == DT_DIR)
			puts(" is a directory");
		else
			puts("");
	}
	n = closedir(tmp);
	printf("%i\n", n);

	ls = ft_parsels(ac, av);
	//ft_lfile_sort(&ls->ldir, ls->flag);
	ft_print_ls(ls);
	ft_print_t_ls(ls);
	return (1);
}