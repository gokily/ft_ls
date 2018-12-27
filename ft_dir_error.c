#include <unistd.h>
#include "ft_ls.h"

t_lfile	*ft_dir_error(int n)
{
	if (n == 1 || n == 2)
		write(1, "Error", 6);
	return (NULL);
}