#include "ft_ls.h"

static int ft_compare_mtim(t_lfile *current, t_lfile *next)
{
	if (prev->mtim.tv_sec < prev->next->mtim.tv_sec)
		return (1);
	else
		return (0);
}

static void	ft_compare_name(t_lfile *current, t_lfile *next)
{
	return (ft_strcmp(current->name, next->name));
}

void		ft_lfile_sort(t_lfile **lfile, unsigned char flag)
{
	if (*lfile == NULL || (*lfile)->next == NULL)
		return ;
	ft_lfile_sort_name(lfile);
	if (flag & MTIM)
		ft_lfile_sort_mtim(lfile);
	if (flag & REV)
		ft_lfile_rev(lfile);
	return ;	
}