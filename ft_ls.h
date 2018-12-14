#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <dirent.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <pwd.h>
#include <time.h>
#include "libft/libft.h"

#include <stdio.h>

# define LONG 1
# define REC 1 << 1
# define ALL 1 << 2
# define REV 1 << 3
# define TIME 1 << 4
# define LSARG 1

typedef struct		s_lfile
{
	char			*name;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	struct timespec	atim;
	struct timespec	mtim;
	struct timespec	ctim;
	struct s_lfile	*next;
}					t_lfile;

typedef	struct		s_ls
{
	unsigned char	flag;
	size_t			nbdir;
	t_lfile			*ldir;
}					t_ls;

t_ls				*ft_parsels(int ac, char **av);

t_lfile	*ft_lfile_new(const char *filepath, unsigned char flag);
void	ft_lfile_push(t_lfile **lst, t_lfile *elem);

void				ft_print_t_ls(t_ls *ls);
#endif