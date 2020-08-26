/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:47:09 by baylak            #+#    #+#             */
/*   Updated: 2020/08/26 20:55:56 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_valid_path(char *path, char *add)
{
	char *ret;
	char *temp;

	if (ft_strcmp(path, "./"))
	{
		temp = ft_strjoin(path, "/");
		ret = ft_strjoin(temp, add);
		ft_strdel(&temp);
	}
	else
		ret = ft_strjoin(path, add);
	return (ret);
}

static void	dir_content(t_files *list, t_dir *dir)
{
	t_files	*subfolder;
	t_files	*tmp;

	subfolder = NULL;
	if (!(dir->dirp = opendir(list->name)))
	{
		//printf("ft_ls: %s: %s\n", list->name, strerror(errno));
		return ;
	}
	while ((dir->dp = readdir(dir->dirp)))
	{
		if (dir->dp->d_name[0] != '.')
		{
			add_elem(&subfolder, dir->dp->d_name);
			subfolder->file_name = ft_strdup(subfolder->name);
			subfolder->name = add_valid_path(list->name, subfolder->name);
			lstat(subfolder->name, &subfolder->mystat);
		}
	}
	closedir(dir->dirp);
	quicksort(subfolder);
	if (dir->options.r)
		reverse_list(&subfolder);
	if (dir->count == 0 || ft_strcmp(subfolder->name, "."))
		reverse_list(&subfolder);
	tmp = subfolder;
	while (subfolder)
	{
		printf("%s\n", subfolder->file_name);
		subfolder = subfolder->next;
	}
	if (dir->options.R)
	{
		subfolder = tmp;
		while (subfolder)
		{
			if (S_ISDIR(subfolder->mystat.st_mode) && ft_strcmp(subfolder->file_name, ".") != 0
												&& ft_strcmp(subfolder->file_name, "..") != 0)
			{
				printf("\n%s:\n", subfolder->name);
				dir_content(subfolder, dir);
			}
			subfolder = subfolder->next;
		}
	}
}

void		print_dir(t_files *list, t_dir *dir, int flag)
{
	if (dir->count >= 2)
	{
		flag > 0 ? printf("\n") : flag;
		printf("%s: \n", list->name);
	}
	dir_content(list, dir);
}