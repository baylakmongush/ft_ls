/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:47:09 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 03:48:53 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_clear_list(t_files **head)
{
	t_files *curr;
	t_files	*temp;

	if (*head != NULL)
	{
		curr = (*head)->next;
		while (curr != NULL && curr != *head)
		{
			temp = curr;
			curr = curr->next;
			free(temp->file_name);
			temp->file_name = NULL;
			free(temp->name);
			temp->name = NULL;
			free(temp);
		}
		free(*head);
		*head = NULL;
	}
}

char		*add_valid_path(char *path, char *add)
{
	char	*ret;
	char	*temp;

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

static void	flag_r_up(t_dir *dir, t_files *subfolder)
{
	t_files	*for_free;

	if (dir->options.R)
	{
		while (subfolder)
		{
			if (S_ISDIR(subfolder->mystat.st_mode)
					&& ft_strcmp(subfolder->file_name, ".") != 0
					&& ft_strcmp(subfolder->file_name, "..") != 0)
			{
				ft_printf("\n%s:\n", subfolder->name);
				dir_content(subfolder, dir);
			}
			for_free = subfolder->next;
			free(subfolder->file_name);
			subfolder->file_name = NULL;
			free(subfolder->name);
			subfolder->name = NULL;
			free(subfolder);
			subfolder = NULL;
			subfolder = for_free;
		}
	}
	else
		ft_clear_list(&subfolder);
}

void		dir_content(t_files *list, t_dir *dir)
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
				perror("lstat");
		}
	}
	closedir(dir->dirp);
	dir->options.t ? sort_time(subfolder) : quicksort(subfolder);
	dir->options.r ? reverse_list(&subfolder) : dir->options.r;
	tmp = subfolder;
	dir->options.l ? print_total(tmp) : dir->options.l;
	while (tmp)
	{
		dir->options.l ?
		display_attr(tmp->name, tmp->file_name, tmp->mystat.st_mode) :
		ft_printf("%s\n", tmp->file_name);
		tmp = tmp->next;
	}
	flag_r_up(dir, subfolder);
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
