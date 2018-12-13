#ifndef FT_LS_H
# define FT_LS_H

#include <sys/types.h>
#include <sys/stat.h>
#include <stdint.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <pwd.h>
#include <time.h>

# define LONG 1
# define REC 1 << 1
# define ALL 1 << 2
# define REV 1 << 3
# define TIME 1 << 4


typedef	struct	s_ls
{
	unsigned char flag;
	size_t		nbdir;
	t_list		*ldir;
}				t_ls;

#endif