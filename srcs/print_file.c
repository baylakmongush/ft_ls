/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:48:52 by baylak            #+#    #+#             */
/*   Updated: 2020/08/28 16:22:41 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		name_print(char *path, char *file_name, mode_t mode)
{
	char		buf[1024];
	ssize_t		len;

	if ((mode & S_IFMT) == S_IFLNK)
	{
		ft_bzero(buf, 1024);
		if ((len = readlink(path, buf, sizeof(buf))) < 0)
		{
			perror("readlink");
			exit(EXIT_FAILURE);
		}
		printf(" %s -> %s\n", file_name, buf);
	}
	else
		printf(" %s\n", file_name);
}

static void		print_time(time_t mtime)
{
	char	*str_time;
	char	*pointer;
	char	*next_point;
	time_t	ct;

	ct = time(NULL);
	if ((str_time = ctime(&mtime)) == NULL)
		return ;
	pointer = str_time + 4;
	next_point = str_time + 10;
	*next_point = '\0';
	printf(" %s", pointer);
	pointer = (mtime + 15778800 < ct) ?
	str_time + 20 : str_time + 11;
	next_point = (mtime + 15778800 < ct) ?
	str_time + 24 : (next_point = str_time + 16);
	if (mtime + 15778800 < ct)
		ft_putchar(' ');
	*next_point = '\0';
	printf(" %s",pointer);
}

void	print_own_rights(struct stat buf)
{
	if(S_ISLNK(buf.st_mode))
        printf("l");
    else if (S_ISREG(buf.st_mode))
        printf("-");
    else if (S_ISDIR(buf.st_mode))
        printf("d");
    else if (S_ISCHR(buf.st_mode))
        printf("c");
    else if (S_ISBLK(buf.st_mode))
        printf("b");
    else if (S_ISFIFO(buf.st_mode))
        printf("f");
    else if (S_ISSOCK(buf.st_mode))
        printf("s");
	if (buf.st_mode & S_IRUSR)
        printf ("r");
    else
        printf ("-");
    if(buf.st_mode&S_IWUSR)
        printf ("w");
    else
        printf ("-");
    if(buf.st_mode & S_IXUSR)
        printf ("x");
    else
        printf ("-");
}

void	print_group_per(struct stat buf)
{
	if (buf.st_mode & S_IRGRP)
        printf("r");
    else
        printf("-");
    if(buf.st_mode & S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXGRP)
        printf("x");
    else
        printf("-");
}

void	print_peop_rights(struct stat buf)
{
	if(buf.st_mode & S_IROTH)
        printf("r");
    else
        printf("-");
    if(buf.st_mode & S_IWOTH)
        printf("w");
    else
        printf("-");
    if(buf.st_mode & S_IXOTH)
        printf("x");
    else
        printf("-");
    printf("  ");
}

void	print_user_group(struct stat buf)
{
	struct passwd* psd;  //Receive the user name of the file owner from this structure
    struct group* grp;

	psd = getpwuid(buf.st_uid);
    grp = getgrgid(buf.st_gid);
    printf("%4d ", buf.st_nlink);  //Link number
    printf("%-3s ", psd->pw_name);
    printf("%-3s ", grp->gr_name);
}

void  display_attr(char* name, char *file_name, mode_t mode)
{
    struct stat buf;
    lstat(name, &buf);
	print_own_rights(buf);
    print_group_per(buf);
    print_peop_rights(buf);
    print_user_group(buf);
	printf("%6lld",buf.st_size);
    print_time(buf.st_mtime);
	name_print(name, file_name, mode);
}

void			print_total(t_files *file)
{
	blkcnt_t	total;
	int			size;

	total = 0;
	if (file)
		size = file->mystat.st_blksize / 1024;
	while (file)
	{
		total += file->mystat.st_blocks;
		file = file->next;
	}
	printf("total %lld\n", total);
}

void	print_file(t_files *list, t_dir *dir)
{
	if (dir->options.l)
		display_attr(list->name, list->name, list->mystat.st_mode);
	else
		printf("%s\n", list->name);
}