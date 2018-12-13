#include "ft_ls.h"

#include <stdio.h>
#include <stdlib.h>

int		main(int ac, char **av)
{
	DIR	*tmp;
	int	n;
	struct stat	*statbuf;

	tmp = opendir("/");
	n = closedir(tmp);
	printf("%i\n", n);

	statbuf = malloc(sizeof(struct stat));
	n = stat("main.c", statbuf);
	printf("Last access of file is at %s", ctime(&statbuf->st_atime));

	ft_print_t_ls(ft_parsels(ac, av));

	return (1);
}