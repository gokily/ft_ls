#include "ft_ls.h"

void	print_t_ls(t_ls *ls)
{
	t_lfile	*elem;
	t_file	*file;

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
		file = elem->file;
		printf("%s last modified at %s\n", (char *)file->name, ctime(&file->mtim.tv_sec));
		elem = elem->next;
	}
	return ;
}
