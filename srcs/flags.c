/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:35:31 by baylak            #+#    #+#             */
/*   Updated: 2020/08/11 14:00:22 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://programmer.help/blogs/implementation-of-ls-a-l-r-r-commands-in-linux.html

#include "ft_ls.h"

t_files				*init_list(t_files *head, char *name)
{
	head = (t_files*)malloc(sizeof(t_files));
	head->name = name;
	head->next = NULL;
	head->prev = NULL;
	return (head);
}

t_files		*add_elem(t_files *files, char *name)
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
	return (files);
}

void				insert_t_files(t_files **head_ptr, t_files *files)
{
        t_files		*current;
		
		current = *head_ptr;
        files->next = NULL;
        if (current == NULL)
		{
            files->prev = NULL;
            *head_ptr = files;
        }
        else
		{
			while (current->next != NULL)
                current = current->next;
            current->next = files;
            files->prev = current;
        }
    }

t_files				*init_file_list(t_dir *dir, char *str)
{
	t_files			*files;
	t_files			*head;

	files = NULL;
	head = files;
	if 	(dir->options.R == 1)
    {
        int len = ft_strlen(dir->PATH);
        if (len > 0)
        {
            if (dir->PATH[len - 1] == '/')
                dir->PATH[len - 1] ='\0';
        }
        if (str[0] == '.' || str[0] == '/')
            ft_strcat(dir->PATH, str);
        else
        {
            ft_strcat(dir->PATH, "/");
            ft_strcat(dir->PATH, str);
        }
		printf(".%s:\n", dir->PATH);
    }
	dir->dirp = opendir(str);
	if (dir->dirp == NULL)
		ft_error("dir");
	while ((dir->dp = readdir(dir->dirp)) != NULL)
	{
		insert_t_files(&head, init_list(files, dir->dp->d_name));
	}
	closedir(dir->dirp);
	return (head);
}

void				flags(t_dir *dir, int arg_num_name)
{
	int				i;

	i = -1;
	if (arg_num_name != 0)
	{
		while (++i < dir->count)
		{
			if (stat(*(dir->name_dir), &dir->mystat) == -1)
			{
				printf("./ft_ls: %s: No such file or directory\n", (*dir->name_dir));
				exit(0);
			}
			if(S_ISDIR(dir->mystat.st_mode))
				dir->files = init_file_list(dir, dir->name_dir[i]);
			else if (S_ISREG(dir->mystat.st_mode))
				printf("%s", dir->name_dir[i]);
		}
	}
	else
		dir->files = init_file_list(dir, ".");
	while (dir->files)
	{
		printf("%s\n", dir->files->name);
		dir->files = dir->files->next;
	}
}