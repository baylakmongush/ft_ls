/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:28 by baylak            #+#    #+#             */
/*   Updated: 2020/08/28 14:33:01 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		init_options(t_dir *dir)
{
	dir->options.a = 0;
	dir->options.l = 0;
	dir->options.R = 0;
	dir->options.r = 0;
	dir->options.t = 0;
}

t_files		*init_list_name(t_dir *dir)
{
	t_files	*list;
	int		i;

	list = NULL;
	i = -1;
	if (!dir)
		return (NULL);
	if (dir->count == 0)
	{
		add_elem(&list, ".");
		return (list);
	}
	while (++i < dir->count)
		add_elem(&list, dir->name_dir[i]);
	if (dir->options.t)
		list = sort_time(list, dir->options.r);
	else
		list = lst_sort_ascii(list);
	if (dir->options.r)
		reverse_list(&list);
	return (list);
}
