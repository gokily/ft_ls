/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:50:48 by gly               #+#    #+#             */
/*   Updated: 2018/12/28 14:56:27 by gly              ###   ########.fr       */
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

typedef struct		s_file
{
	char			*name;
	char			*fullpath;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	blksize_t		blksize;
	blkcnt_t		blkcnt;
	struct timespec	atim;
	struct timespec	mtim;
	struct timespec	ctim;
}					t_file;

typedef struct		s_lfile
{
	t_file			*file;	
	struct s_lfile	*next;
}					t_lfile;

typedef	struct		s_ls
{
	unsigned char	flag;
	size_t			nbdir;
	t_lfile			*ldir;
}					t_ls;

t_ls				*ft_parsels(int ac, char **av);

t_lfile	*ft_lfile_new(char *filepath, unsigned char flag);
void	ft_lfile_push(t_lfile **lst, t_lfile *elem);
void	ft_lfile_sort(t_lfile **lfile, unsigned char flag);
void	ft_lfile_delall(t_lfile *file);

t_ls	*ft_t_ls_new(void);


void	ft_print_ls(t_ls *ls);
int		ft_print_dir(t_lfile *dir, t_ls *ls);
void		ft_print_lfile(t_lfile *file, unsigned char flag);
void	ft_print_file_short(t_file *file);
void	ft_print_file_long(t_file *file, unsigned char flag);

char	*ft_ls_time(time_t time);

t_lfile	*ft_dir_error(int n);

//libft
char	*ft_strjoin_three(char *first, char *second, char *third);

//debug
void				print_t_ls(t_ls *ls);
#endif
