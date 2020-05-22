/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Student <Student@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/05/21 23:54:23 by Student          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void sort(char **strlist, int strcnt)
{
	for(int i = 0; i < strcnt - 1; i++)
		for(int j = i + 1; j < strcnt; j++)
			if(ft_strcmp(strlist[i], strlist[j]) > 0) {
				char* tmp = strlist[i];
				strlist[i] = strlist[j];
				strlist[j] = tmp;
			}
}

int					main(int argc, char **argv)
{
	DIR				*dp;
	struct dirent	*dirp;
	struct stat 	mystat;
	int				size;
	char			*buf[512];
	int				i;
	int				j;

	if (argc == 1)
	{
		if ((dp = opendir(".")) == NULL)
		{
			perror("ft_ls: dir");
			exit(0);
		}
		i = 0;
		while ((dirp = readdir(dp)) != NULL)
		{
			if (ft_strcmp(dirp->d_name, ".") == 0 || ft_strcmp(dirp->d_name, "..") == 0 || ft_strncmp(dirp->d_name, ".", 1) == 0)
				continue;
			buf[i] = (char*)malloc(sizeof(char) * (ft_strlen(dirp->d_name) + 1));
			buf[i] = ft_strcpy(buf[i], dirp->d_name);
			i++;
		}
		closedir(dp);
		sort(buf, i);
		j = 0;
		while (j < i)
		{
			ft_putstr(buf[j]);
			ft_putstr("\n");
			free(buf[j]);
			buf[j] = NULL;
			j++;
		}
		return (0);	
	}
	if ((dp = opendir(argv[1])) == NULL)
	{
		perror("ft_ls: dir");
		exit(0);
	}
	while ((dirp = readdir(dp)) != NULL)
	{
        stat(dirp->d_name, &mystat);
		size = mystat.st_size;
        ft_putnbr(size);
		ft_putchar(' ');
        ft_putstr(dirp->d_name);
		ft_putchar('\n');
	}
	closedir(dp);
	return (0);
}
