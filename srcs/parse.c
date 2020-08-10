/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:27:32 by baylak            #+#    #+#             */
/*   Updated: 2020/08/11 00:00:25 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			print_usage(char str)
{
	printf("ls: illegal option -- %c\n", str);
	printf("usage: ls [-ALRalrt] [file ...]\n");
	exit(1);
}

int				parse_options(t_options *options, char **argv, int i)
{
	size_t		j;

	if (argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (++j < ft_strlen(argv[i]))
		{
			if (argv[i][j] == 'a' || argv[i][j] == 'A' || argv[i][j] == 'R' ||
				argv[i][j] == 'r' || argv[i][j] == 't')
			{
				options->a = (argv[i][j] == 'a' ||
								argv[i][j] == 'A') ? 1 : options->a;
				options->l = (argv[i][j] == 'l' ||
								argv[i][j] == 'L') ? 1 : options->l;
				options->R = (argv[i][j] == 'R') ? 1 : options->R;
				options->r = (argv[i][j] == 'r') ? 1 : options->r;
				options->t = (argv[i][j] == 't') ? 1 : options->t;
			}
			else
				print_usage(argv[i][j]);
		}
	}
	else if (argv[i][0] != '-' || argv[1][0] != '-')
		return (0);
	return (1);
}

int				parse(t_options *options, t_dir *dir, int argc, char **argv)
{
	size_t		i;

	i = 0;
	dir->a = 0;
	while (++i < (size_t)argc)
	{
		if (parse_options(options, argv, i) == 0)
			return (0);
	}
	return (1);
}
