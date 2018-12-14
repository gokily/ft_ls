#include "ft_ls.h"

static void ft_lfile_swap(t_lfile **prev, t_lfile **current)
{
	t_lfile	*tmp;

	tmp = *prev;
	*prev = *current;
	*current = tmp;
	(*current)->next = (*prev)->next;
	(*prev)->next = *current;
}

static void	ft_lfile_sort_mtim(t_lfile **lfile)
{
	t_lfile		*prev;
	unsigned char	flag;

	flag = 0;
	while (flag == 0)
	{
		prev = *lfile;
		flag = 1;
		while (prev->next != NULL)
		{
			if (prev->mtim.tv_sec < prev->next->mtim.tv_sec)
			{
				ft_lfile_swap(&prev, &(prev->next));
				flag = 0;
			}
			else
				prev = prev->next;
		}
	}
	return ;
}

static void	ft_lfile_sort_name(t_lfile **lfile)
{
	t_lfile		*prev;
	unsigned char	flag;

	flag = 0;
	while (flag == 0)
	{
		prev = *lfile;
		printf("Initialize, lfile is %s\n", prev->name);
		flag = 1;
		while (prev->next != NULL)
		{
			printf("Compare, prev is %s and prev->next is %s\n",
				prev->name, prev->next->name);
			if (ft_strcmp(prev->name, prev->next->name) > 0)
			{
				puts("SWAPPING");
				ft_lfile_swap(&prev, &(prev->next));
				flag = 0;
			}
			else
				prev = prev->next;
		}
	}
	return ;
}

void		ft_lfile_sort(t_lfile **lfile, unsigned char flag)
{
	if (*lfile == NULL || (*lfile)->next == NULL)
		return ;
	ft_lfile_sort_name(lfile);
	if (flag & MTIM)
		ft_lfile_sort_mtim(lfile);
	return ;	
}