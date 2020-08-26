/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:48:52 by baylak            #+#    #+#             */
/*   Updated: 2020/08/27 02:17:31 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_time(time_t mod_time)
{
	char	*str;
	char	*start;
	char	*end;
	time_t	ct;

	ct = time(NULL);
	if ((str = ctime(&mod_time)) == NULL)
		return ;
	start = str + 4;
	end = str + 10;
	*end = 0;
	printf(" %s ",start);
	start = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 20 : str + 11;
	end = (mod_time > ct || mod_time + SIX_MONTHS < ct) ?
	str + 24 : (end = str + 16);
	if (mod_time > ct || mod_time + SIX_MONTHS < ct)
		ft_putchar(' ');
	*end = 0;
	printf("%s ",start);
}

void  display_attribute(char* name, char *file_name)  //Print the - l parameter in the corresponding format
{
    struct stat buf;
    //char buff_time[32];
    struct passwd* psd;  //Receive the user name of the file owner from this structure
    struct group* grp;   //Get group name
    lstat(name, &buf);
    if(S_ISLNK(buf.st_mode))
        printf("l");
    else if(S_ISREG(buf.st_mode))
        printf("-");
    else if(S_ISDIR(buf.st_mode))
        printf("d");
    else if(S_ISCHR(buf.st_mode))
        printf("c");
    else if(S_ISBLK(buf.st_mode))
        printf("b");
    else if(S_ISFIFO(buf.st_mode))
        printf("f");
    else if(S_ISSOCK(buf.st_mode))
        printf("s");
    //Get Print File Owner Rights
    if (buf.st_mode & S_IRUSR)
        printf("r");
    else
        printf("-");
    if(buf.st_mode&S_IWUSR)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXUSR)
        printf("x");
    else
        printf("-");

    //All group permissions
    if(buf.st_mode&S_IRGRP)
        printf("r");
    else
        printf("-");
    if(buf.st_mode&S_IWGRP)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXGRP)
        printf("x");
    else
        printf("-");

    //Other people's rights
    if(buf.st_mode&S_IROTH)
        printf("r");
    else
        printf("-");
    if(buf.st_mode&S_IWOTH)
        printf("w");
    else
        printf("-");
    if(buf.st_mode&S_IXOTH)
        printf("x");
    else
        printf("-");
    printf("  ");
    //Get the user name and group name of the file owner based on uid and gid
    psd = getpwuid(buf.st_uid);
    grp = getgrgid(buf.st_gid);
    printf("%4d ",buf.st_nlink);  //Link number
    printf("%-8s ",psd->pw_name);
    printf("%-8s ",grp->gr_name);
	printf("%6lld",buf.st_size);
    print_time(buf.st_mtime);
	printf("%s\n", file_name);
}

void	print_file(t_files *list, t_dir *dir)
{
	if (dir->options.l)
		display_attribute(list->name, list->name);
	else
		printf("%s\n", list->name);
}