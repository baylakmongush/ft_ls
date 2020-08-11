/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/11 12:08:01 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init(t_dir *dir)
{
	dir->options.a = 0;
	dir->options.l = 0;
	dir->options.R = 0;
	dir->options.r = 0;
	dir->options.t = 0;
}

int				main(int argc, char **argv)
{
	t_dir		dir;

	init(&dir);
	dir.arg_num_name = parse_options(&dir, argc, argv);
	if (dir.arg_num_name != 0)
		parse_folders(argc, argv, dir.arg_num_name, &dir); // free dir.name_dir
	flags(&dir, dir.arg_num_name);
	return (0);
}
