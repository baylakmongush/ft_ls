/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/11 05:08:45 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init(t_options *options)
{
	options->a = 0;
	options->l = 0;
	options->R = 0;
	options->r = 0;
	options->t = 0;
}

int				main(int argc, char **argv)
{
	t_options	options;
	t_dir		dir;

	init(&options);
	dir.arg_num_name = parse_options(&options, argc, argv);
	printf("%d", dir.arg_num_name);
	printf("r = %d, a = %d", options.R, options.a);
	if (dir.arg_num_name != 0)
		parse_folders(argc, argv, dir.arg_num_name, &dir); // free dir.name_dir
	flags(&dir, options, dir.arg_num_name);
	return (0);
}
