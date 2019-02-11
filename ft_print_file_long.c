#include "ft_ls.h"

int filetypeletter(int mode)
{
    char    c;

    if (S_ISREG(mode))
        c = '-';
    else if (S_ISDIR(mode))
        c = 'd';
    else if (S_ISBLK(mode))
        c = 'b';
    else if (S_ISCHR(mode))
        c = 'c';
    else if (S_ISFIFO(mode))
        c = 'p';
    else if (S_ISLNK(mode))
        c = 'l';
    else if (S_ISSOCK(mode))
        c = 's';
    else
        c = '?';
    return(c);
}

char    *ft_lsperms(int mode)
{
    static const char *rwx[] = {"---", "--x", "-w-", "-wx",
    "r--", "r-x", "rw-", "rwx"};
	char	*perms;

	if (!(perms = ft_strnew(10)))
	    return (NULL);
    perms[0] = filetypeletter(mode);
    ft_strcpy(&perms[1], rwx[(mode >> 6) & 7]);
    ft_strcpy(&perms[4], rwx[(mode >> 3) & 7]);
    ft_strcpy(&perms[7], rwx[(mode & 7)]);
    if (mode & S_ISUID)
        perms[3] = (mode & S_IXUSR) ? 's' : 'S';
    if (mode & S_ISGID)
        perms[6] = (mode & S_IXGRP) ? 's' : 'l';
    if (mode & S_ISVTX)
        perms[9] = (mode & S_IXOTH) ? 't' : 'T';
    return(perms);
}

void	ft_print_file_long(t_file *file, unsigned char flag)
{
	char	*perms;
	
	perms = ft_lsperms(file->mode);
	(void)flag;
	//ft_printf("%s\t%u\t%s\t%s\t%u\t%s\t%s\n", perms, file->nlink, file->uid,
	//	file->gid, file->size, ctime(file->mtim), file->name);
	
	//need to correct the ctime thing, maybe make own version
	printf("%s\t%u\t%u\t%u\t%u\t%s\t%s\n", perms, (unsigned int)file->nlink, file->uid,
		file->gid, (unsigned int)file->size, file->name, ctime(&file->mtim.tv_sec));
	return ;
}
