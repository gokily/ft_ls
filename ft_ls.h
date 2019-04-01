/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:50:48 by gly               #+#    #+#             */
/*   Updated: 2019/04/01 14:45:54 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
# define MTIM 1 << 4
# define SEVERAL 1 << 5
# define LSARG 1
# define BUFFSIZE 1024
#define COL_RED     "\x1b[31m"
#define COL_GREEN   "\x1b[32m"
#define COL_YELLOW  "\x1b[33m"
#define BG_YELLOW  "\x1b[43m"
#define COL_BLUE    "\x1b[34m"
#define COL_MAGENTA "\x1b[35m"
#define COL_CYAN "\x1b[96m"
#define BG_CYAN "\x1b[46m"
#define COLRESET   "\x1b[0m"

typedef struct		s_file
{
	char			*name;
	char			*fullpath;
	mode_t			mode;
	nlink_t			nlink;
	char			*uid;
	char			*gid;
	off_t			size;
	blksize_t		blksize;
	blkcnt_t		blkcnt;
	dev_t			rdev;
	char			*link;
	struct timespec	atim;
	struct timespec	mtim;
	struct timespec	ctim;
	int				ext;
	int				acl;
	char			*col;
}					t_file;

typedef struct		s_lfile
{
	t_file			*file;	
	struct s_lfile	*next;
}					t_lfile;

typedef	struct		s_linfo
{
	int				maxl;
	int				nb;
}					t_linfo;

typedef	struct		s_ls
{
	unsigned char	flag;
	size_t			nbdir;
	t_lfile			*ldir;
}					t_ls;

typedef struct		s_space
{
	int	one;
	int	two;
	int	three;
	int	four_a;
	int	four_b;
	int	four_c;
}					t_space;


t_ls				*ft_parsels(int ac, char **av);

t_lfile	*ft_lfile_new(char *filepath, unsigned char flag);
void	ft_lfile_push(t_lfile **lst, t_lfile *elem);
void	ft_lfile_sort(t_lfile **lfile, unsigned char flag);
void	ft_lfile_delall(t_lfile *file);

t_ls	*ft_t_ls_new(void);


void	ft_print_ls(t_ls *ls);
int		ft_print_dir(t_lfile *dir, t_ls *ls);
int		ft_print_lfile(t_lfile *file, unsigned char flag);
int		ft_print_lfile_short(t_lfile *file);
int		ft_print_lfile_long(t_lfile *file, unsigned char flag);
t_space	ft_calculate_space(t_lfile *file, unsigned char flag);

char	*ft_get_time(struct timespec file_timespec);

int		ft_dir_error(int n);

//libft
char	*ft_strjoin_three(char *first, char *second, char *third);

//debug
void				print_t_ls(t_ls *ls);
#endif
