/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 13:34:28 by baylak            #+#    #+#             */
/*   Updated: 2020/08/17 15:04:51 by baylak           ###   ########.fr       */
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
	while (++i < dir->count)
		add_elem(&list, dir->name_dir[i]);
	sorted_list(&list);
	return (list);
}
