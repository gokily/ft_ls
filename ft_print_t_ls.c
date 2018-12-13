#include "ft_ls.h"


#include <stdio.h>

void	ft_print_t_ls(t_ls *ls)
{
	t_list	*elem;
	if (ls == NULL)
	{
		puts("struct is null");
		return ;
	}
	printf("Flags are %i\n", (int)ls->flag);
	printf("Number of directories is %lu and the directory/ies is/are:\n", ls->nbdir);
	elem = ls->ldir;
	while (elem)
	{
		printf("%s\n", (char *)elem->content);
		elem = elem->next;
	}
	return ;
}