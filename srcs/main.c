/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/10 23:36:07 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			init(t_options *options, t_dir *dir)
{
	options->a = 0;
	options->l = 0;
	options->R = 0;
	options->r = 0;
	options->t = 0;
	dir->a = 3;
}

int				main(int argc, char **argv)
{
	t_options	options;
	t_dir		dir;

	init(&options, &dir);
	parse(&options, &dir, argc, argv);
	printf("r = %d, a = %d", options.R, options.a);
	return (0);
}
