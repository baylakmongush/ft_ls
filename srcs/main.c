/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 18:24:31 by Student           #+#    #+#             */
/*   Updated: 2020/08/10 21:25:14 by baylak           ###   ########.fr       */
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

int				parse(t_options *options, t_dir *dir, int argc, char **argv)
{
	size_t		i;
	size_t		j;

	i = -1;
	dir->a = 0;
	while (++i < (size_t)argc)
	{
		if (argv[i][0] == '-')
		{
			j = 0;
			while (++j < ft_strlen(argv[i]))
			{
				if (argv[i][j] == 'a' || argv[i][j] == 'A' || argv[i][j] == 'R' ||
					argv[i][j] == 'r' || argv[i][j] == 't')
				{
					options->a = (argv[i][j] == 'a' || argv[i][j] == 'A') ? 1 : options->a;
					options->l = (argv[i][j] == 'l' || argv[i][j] == 'L') ? 1 : options->l;
					options->R = (argv[i][j] == 'R') ? 1 : options->R;
					options->r = (argv[i][j] == 'r') ? 1 : options->r;
					options->t = (argv[i][j] == 't') ? 1 : options->t;
				}
				else
				{
					printf("ls: illegal option -- %c\n", argv[i][j]);
					printf("usage: ls [-@ALRalrt] [file ...]\n");
					return (0);
				}
			}
		}	
	}
	return (1);
}

int				main(int argc, char **argv)
{
	t_options	options;
	t_dir		dir;

	init(&options, &dir);
	if (parse(&options, &dir, argc, argv) == 0)
		return (0);
	printf("r = %d, a = %d", options.R, options.a);
	return (0);
}
