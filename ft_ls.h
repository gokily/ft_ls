/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gly <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 14:50:48 by gly               #+#    #+#             */
/*   Updated: 2019/04/19 17:11:58 by gly              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <dirent.h>
# include <string.h>

# define LNG 1
# define REC 1 << 1
# define ALL 1 << 2
# define REV 1 << 3
# define MTIM 1 << 4
# define ATIM 1 << 5
# define SEVERAL 1 << 6
# define COLUMN 1 << 7
# define COLOR 1 << 8
# define ENDOPT 1 << 9
# define FIRST 1 << 10
# define LDIR 1 << 11
# define LSARG 1
# define BUFFSIZE 1024
# define LSOPTION "CGMRalrtu1"
# define COLRESET   "\x1b[0m"

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
	int				ncol;
	int				nrow;
	int				i;
	int				j;
	int				k;
}					t_linfo;

typedef	struct		s_ls
{
	unsigned int	flag;
	size_t			nbdir;
	int				status;
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

t_lfile				*ft_lfile_new(char *filepath, unsigned int lsflag,
		unsigned int flag, t_ls *ls);
void				ft_lfile_push(t_lfile **lst, t_lfile *elem);
void				ft_lfile_sort(t_lfile **lfile, unsigned int flag);
void				ft_lfile_delall(t_lfile *file);

t_ls				*ft_t_ls_new(void);

int					ft_print_dir(t_lfile *dir, t_ls *ls);
int					ft_print_lfile(t_lfile *file, unsigned int flag);
int					ft_print_lfile_short(t_lfile *file, unsigned int flag);
int					ft_print_lfile_long(t_lfile *file, unsigned int flag);
t_space				ft_calculate_space(t_lfile *file);

char				*ft_get_time(struct timespec file_timespec);
int					ft_set_colors(t_file *file, char **col, unsigned int flag);

int					ft_compare_mtim(t_file *current, t_file *next);
int					ft_compare_atim(t_file *current, t_file *next);
int					ft_compare_name(t_file *current, t_file *next);
int					ft_is_dir(t_file *current, t_file *next);

int					ft_dir_error(char *file, t_ls *ls);

#endif
