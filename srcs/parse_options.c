/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:27:32 by baylak            #+#    #+#             */
/*   Updated: 2020/08/11 01:32:15 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			parse_options_body(t_options *options, char **argv, int i, size_t j)
{
	if (argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (++j < ft_strlen(argv[i]))
		{
			if (argv[i][j] == 'a' || argv[i][j] == 'A' || argv[i][j] == 'R' ||
				argv[i][j] == 'r' || argv[i][j] == 't' || argv[i][j] == 'l' ||
				argv[i][j] == 'L')
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
		return (i);
	return (0);
}

int			parse_options(t_options *options, int argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		arg_num_name;

	i = 0;
	j = 0;
	while (++i < (size_t)argc)
	{
		if ((arg_num_name = parse_options_body(options, argv, i, j)) != 0)
			return (arg_num_name);
	}
	return (0);
}
