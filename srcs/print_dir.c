/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:47:09 by baylak            #+#    #+#             */
/*   Updated: 2020/08/28 18:40:22 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*add_valid_path(char *path, char *add)
{
	char *ret;
	char *temp;

	if (ft_strcmp(path, "./") && ft_strcmp(path, "/") != 0)
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
		return ;
	while ((dir->dp = readdir(dir->dirp)))
	{
		if (dir->dp->d_name[0] != '.' || dir->options.a)
		{
			add_elem(&subfolder, dir->dp->d_name);
			subfolder->file_name = ft_strdup(subfolder->name);
			subfolder->name = add_valid_path(list->name, subfolder->name);
			if (lstat(subfolder->name, &subfolder->mystat) == -1)
			{
				perror("lstat");
				exit(EXIT_FAILURE);
			}
		}
	}
	closedir(dir->dirp);
	if (dir->options.t)
		sort_time(subfolder);
	else
		quicksort(subfolder);
	if (dir->options.r)
		reverse_list(&subfolder);
	tmp = subfolder;
	if (dir->options.l)
		print_total(tmp);
	while (tmp)
	{
		if (dir->options.l)
			display_attr(tmp->name, tmp->file_name, tmp->mystat.st_mode);
		else
			ft_printf("%s\n", tmp->file_name);
		tmp = tmp->next;
	}
	if (dir->options.R)
	{
		while (subfolder)
		{
			if (S_ISDIR(subfolder->mystat.st_mode) && ft_strcmp(subfolder->file_name, ".") != 0
												&& ft_strcmp(subfolder->file_name, "..") != 0)
			{
				ft_printf("\n%s:\n", subfolder->name);
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
		flag > 0 ? ft_printf("\n") : flag;
		ft_printf("%s: \n", list->name);
	}
	dir_content(list, dir);
}
