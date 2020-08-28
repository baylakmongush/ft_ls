/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/28 23:29:57 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int				ft_ls(t_files *list, t_dir *dir)
{
	int			flag;

	flag = 0;
	while (list != NULL)
	{
		if (ft_strlen(list->name) > PATH_MAX)
		{
			ft_printf("./ft_ls: %s: File name too long\n", list->name);
			list = list->next;
			continue ;
		}
		if (lstat(list->name, &list->mystat) == -1)
		{
			perror("lstat");
			list = list->next;
			continue ;
		}
		if (S_ISDIR(list->mystat.st_mode))
			print_dir(list, dir, flag);
		else if (S_ISREG(list->mystat.st_mode))
			print_file(list, dir);
		else if (ft_strcmp(list->name, "-"))
			return (0);
		else
			return (0);
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
		parse_folders(argc, argv, dir.arg_num_name, &dir); // free dir.name_dir
	else if (dir.arg_num_name < 0)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", argv[1]);
		return (0);
	}
	list = init_list_name(&dir);
	if (!ft_ls(list, &dir))
		ft_printf("ft_ls: : %s: No such file or directory\n", list->name);
	return (0);
}
