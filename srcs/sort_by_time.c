/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_time.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 13:00:01 by baylak            #+#    #+#             */
/*   Updated: 2020/08/30 12:52:40 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				cmp_times(long t1, long t2, char *name1, char *name2)
{
	return (t1 == t2 ? ft_strcmp(name1, name2) : t1 - t2);
}

int				swap_with_stats(t_files *path, t_files *tmp,
							struct stat *curr_stat, struct stat *next_stat)
{
	if (lstat(path->name, curr_stat) == -1)
	{
		path = path->next;
		return (0);
	}
	if (lstat(tmp->name, next_stat) == -1)
	{
		tmp = tmp->next;
		return (0);
	}
	if (cmp_times((*curr_stat).st_ctimespec.tv_sec,
								(*next_stat).st_ctimespec.tv_sec,
			path->file_name, tmp->file_name) < 0)
		swap(path, tmp);
	return (1);
}

t_files			*sort_time(t_files *path)
{
	t_files		*begin;
	t_files		*tmp;
	struct stat next_stat;
	struct stat curr_stat;

	tmp = NULL;
	if (path == NULL)
		return (NULL);
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			if (!swap_with_stats(path, tmp, &curr_stat, &next_stat))
				continue ;
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}
