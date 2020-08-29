/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 00:01:45 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 22:37:33 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			swap(t_files *a, t_files *b)
{
	char		*file_name;
	char		*name;
	struct stat tmp;

	name = NULL;
	file_name = NULL;
	file_name = a->file_name;
	name = a->name;
	tmp = a->mystat;
	a->file_name = b->file_name;
	a->name = b->name;
	a->mystat = b->mystat;
	b->name = name;
	b->file_name = file_name;
	b->mystat = tmp;
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

void			print_usage(char str)
{
	ft_printf("ls: illegal option -- %c\n", str);
	ft_printf("usage: ls [-alRrt] [file ...]\n");
	exit(1);
}

char			*add_valid_path(char *path, char *add)
{
	char		*ret;
	char		*temp;

	if (!*path || !*add)
		return (NULL);
	if (ft_strcmp(path, "./") && ft_strcmp(path, "/") != 0)
	{
		temp = ft_strjoin(path, "/");
		ret = ft_strjoin(temp, add);
		ft_strdel(&temp);
	}
	else
		ret = ft_strjoinfree_both(path, add);
	return (ret);
}
