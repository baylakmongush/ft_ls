/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 19:47:09 by baylak            #+#    #+#             */
/*   Updated: 2020/08/17 21:27:30 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	dir_content(t_files *list, t_dir *dir)
{
	
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