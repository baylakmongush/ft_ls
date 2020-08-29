/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/29 23:12:31 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		print_dir_or_file(t_files *list, t_dir *dir, int flag)
{
	if (S_ISDIR(list->mystat.st_mode))
		print_dir(list, dir, flag);
	else if (S_ISREG(list->mystat.st_mode))
		print_file(list, dir);
	else
		exit(0);
}

int				ft_ls(t_files *list, t_dir *dir)
{
	int			flag;

	flag = 0;
	while (list != NULL)
	{
		if (ft_strlen(list->name) > PATH_MAX)
		{
			ft_printf("./ft_ls: %s: File name too long\n",
								list->name);
			list = list->next;
			continue ;
		}
		if (lstat(list->name, &list->mystat) == -1)
		{
			ft_printf("./ft_ls: %s: No such file or directory\n",
								list->file_name);
			list = list->next;
			continue ;
		}
		print_dir_or_file(list, dir, flag);
		flag++;
		list = list->next;
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_dir		dir;
	t_files		*list;

	init_options(&dir);
	dir.arg_num_name = parse_options(&dir, argc, argv);
	if (dir.arg_num_name > 0)
		parse_folders(argc, argv, dir.arg_num_name, &dir);
	else if (dir.arg_num_name < 0)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", argv[1]);
		return (0);
	}
	list = init_list_name(&dir);
	ft_ls(list, &dir);
	ft_clear_list(&list);
	return (0);
}
