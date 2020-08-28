/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:48:52 by baylak            #+#    #+#             */
/*   Updated: 2020/08/28 23:54:38 by baylak           ###   ########.fr       */
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
		ft_printf(" %s -> %s\n", file_name, buf);
	}
	else
		ft_printf(" %s\n", file_name);
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
	ft_printf(" %-2s", pointer);
	pointer = (mtime + 15778800 < ct) ?
	str_time + 20 : str_time + 11;
	next_point = (mtime + 15778800 < ct) ?
	str_time + 24 : (next_point = str_time + 16);
	if (mtime + 15778800 < ct)
		ft_putchar(' ');
	*next_point = '\0';
	ft_printf(" %s",pointer);
}

void	print_own_rights(struct stat buf)
{
	if(S_ISLNK(buf.st_mode))
        ft_printf("l");
    else if (S_ISREG(buf.st_mode))
        ft_printf("-");
    else if (S_ISDIR(buf.st_mode))
        ft_printf("d");
    else if (S_ISCHR(buf.st_mode))
        ft_printf("c");
    else if (S_ISBLK(buf.st_mode))
        ft_printf("b");
    else if (S_ISFIFO(buf.st_mode))
        ft_printf("f");
    else if (S_ISSOCK(buf.st_mode))
        ft_printf("s");
	if (buf.st_mode & S_IRUSR)
        ft_printf ("r");
    else
        ft_printf ("-");
    if(buf.st_mode&S_IWUSR)
        ft_printf ("w");
    else
        ft_printf ("-");
    if(buf.st_mode & S_IXUSR)
        ft_printf ("x");
    else
        ft_printf ("-");
}

void	print_group_per(struct stat buf)
{
	if (buf.st_mode & S_IRGRP)
        ft_printf("r");
    else
        ft_printf("-");
    if(buf.st_mode & S_IWGRP)
        ft_printf("w");
    else
        ft_printf("-");
    if(buf.st_mode&S_IXGRP)
        ft_printf("x");
    else
        ft_printf("-");
}

void	print_peop_rights(struct stat buf)
{
	if(buf.st_mode & S_IROTH)
        ft_printf("r");
    else
        ft_printf("-");
    if(buf.st_mode & S_IWOTH)
        ft_printf("w");
    else
        ft_printf("-");
    if(buf.st_mode & S_IXOTH)
        ft_printf("x");
    else
        ft_printf("-");
}

void	print_user_group(struct stat buf)
{
	struct passwd* passd;
    struct group* group;

	passd = getpwuid(buf.st_uid);
    group = getgrgid(buf.st_gid);
    ft_printf("%2d", buf.st_nlink);  //Link number
    ft_printf(" %3s ", passd->pw_name);
    ft_printf("%3s ", group->gr_name);
}

void	display_ext_attr(char *path)
{
	acl_t acl = NULL;
    acl_entry_t dummy;
    ssize_t xattr = 0;
    char chr;

    acl = acl_get_link_np(path, ACL_TYPE_EXTENDED);
    if (acl && acl_get_entry(acl, ACL_FIRST_ENTRY, &dummy) == -1) {
        acl_free(acl);
        acl = NULL;
    }
    xattr = listxattr(path, NULL, 0, XATTR_NOFOLLOW);
    if (xattr < 0)
        xattr = 0;
    if (xattr > 0)
        chr = '@';
    else if (acl != NULL)
        chr = '+';
    else
        chr = ' ';
    ft_printf("%c ", chr);
}

void  display_attr(char* name, char *file_name, mode_t mode)
{
    struct stat buf;
    if (lstat(name, &buf) == -1)
	{
		perror("lstat");
		return ;
	}
	print_own_rights(buf);
    print_group_per(buf);
    print_peop_rights(buf);
	display_ext_attr(name);
    print_user_group(buf);
	ft_printf("%4lld",buf.st_size);
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
	ft_printf("total %lld\n", total);
}

void	print_file(t_files *list, t_dir *dir)
{
	if (dir->options.l)
		display_attr(list->name, list->name, list->mystat.st_mode);
	else
		ft_printf("%s\n", list->name);
}