/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:35:31 by baylak            #+#    #+#             */
/*   Updated: 2020/08/11 05:39:22 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				init_list(t_files **files, char *name)
{
	*files = (t_files*)malloc(sizeof(t_files));
	(*files)->name = name;
	(*files)->next = NULL;
	(*files)->prev = NULL;
}

t_files				*add_elem(t_files *files, char *name)
{
	t_files *temp;
	t_files	*p;

	temp = (t_files*)malloc(sizeof(t_files));
	p = files->next;
	files->next = temp;
	temp->name = name;
	temp->next = p;
	temp->prev = files;
	if (p != NULL)
		p->prev = temp;
	return (temp);
}

t_files				*recursively_list(char *str)
{
	char			path[1024];
	DIR				*dirp;
	struct dirent	*dp;
	t_files			*files;

	files = NULL;
	dirp = opendir(str);
	if (!dirp)
        return (NULL);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (ft_strcmp(dp->d_name, ".") != 0 && ft_strcmp(dp->d_name, "..") != 0)
		{
			files = add_elem(files, dp->d_name);
			printf("<%s\n>", files->name);
			ft_strcpy(path, str);
			ft_strcat(path, "/");
			ft_strcat(path, dp->d_name);
			recursively_list(path);
		}
	}
	closedir(dirp);
	return (files);
}

void				flags(t_dir *dir, t_options options, int arg_num_name)
{
	int				i;

	i = -1;
	if (options.R)
	{
		if (arg_num_name != 0)
		{
			init_list(&dir->files, NULL);
			while (++i < dir->count)
				recursively_list(dir->name_dir[i]);
		}
		else
			recursively_list(".");
	}
}