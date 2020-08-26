/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/26 20:36:24 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://programmer.help/blogs/implementation-of-ls-a-l-r-r-commands-in-linux.html

#include "ft_ls.h"

void			ft_ls(t_files *list, t_dir *dir)
{
	int			flag;

	flag = 0;
	while (list != NULL)
	{
		lstat(list->name, &list->mystat);
		if (S_ISDIR(list->mystat.st_mode))
			print_dir(list, dir, flag);
		else
			print_file(list);
		flag++;
		list = list->next;
	}
}

int				main(int argc, char **argv)
{
	t_dir		dir;
	t_files		*list;

	init_options(&dir);
	dir.arg_num_name = parse_options(&dir, argc, argv);
	if (dir.arg_num_name != 0)
		parse_folders(argc, argv, dir.arg_num_name, &dir); // free dir.name_dir
	list = init_list_name(&dir);
	ft_ls(list, &dir);
	return (0);
}
