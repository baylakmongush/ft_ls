/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/17 15:06:36 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//https://programmer.help/blogs/implementation-of-ls-a-l-r-r-commands-in-linux.html

#include "ft_ls.h"

int				main(int argc, char **argv)
{
	t_dir		dir;
	t_files		*list;

	init_options(&dir);
	dir.arg_num_name = parse_options(&dir, argc, argv);
	if (dir.arg_num_name != 0)
		parse_folders(argc, argv, dir.arg_num_name, &dir); // free dir.name_dir
	list = init_list_name(&dir);
	if (dir.options.r)
		reverse_list(&list);
	while (list != NULL)
	{
		printf("%s", list->name);
		list = list->next;
	}
	return (0);
}
