/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:27:32 by baylak            #+#    #+#             */
/*   Updated: 2020/08/10 21:28:59 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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