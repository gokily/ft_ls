#include "ft_ls.h"

//La fonction qui va appeler les differents repertoires appeles par ls.
//Voir si on ne veut pas un retour pour ft_print_dir
void	ft_print_ls(t_ls *ls)
{
	t_lfile	*ldir;

	ldir = ls->ldir;
	if (ls->nbdir > 1)
		ls->flag |= SEVERAL;
	while (ldir != NULL)
	{
		ft_print_dir(ldir, ls->flag);
		ldir = ldir->next;
	}
	return ;
}
