#include "ft_ls.h"

t_ls	*ft_t_ls_new(void)
{
	t_ls	*ls;

	if (!(ls = malloc(sizeof(t_ls))))
		return (NULL);
	ls->nbdir = 0;
	ls->flag = FIRST;
	ls->ldir = NULL;
	ls->status = 0;
	return (ls);
}
