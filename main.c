#include "ft_ls.h"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	DIR	*tmp;
	int	n;
	struct stat	*statbuf;
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
	ft_print_t_ls(ls);
	if (ls != NULL)
		puts("parsel");
	return (1);
}