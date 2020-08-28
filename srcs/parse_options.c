/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 21:27:32 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 03:28:47 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		insert_options(t_dir *dir, char flag)
{
	dir->options.a = (flag == 'a') ? 1 : dir->options.a;
	dir->options.l = (flag == 'l') ? 1 : dir->options.l;
	dir->options.R = (flag == 'R') ? 1 : dir->options.R;
	dir->options.r = (flag == 'r') ? 1 : dir->options.r;
	dir->options.t = (flag == 't') ? 1 : dir->options.t;
}

int			parse_options_body(t_dir *dir, char **argv, int i, int argc)
{
	size_t	j;

	if (argv[i][0] == '-' && argv[i][1])
	{
		j = 0;
		while (++j < ft_strlen(argv[i]))
		{
			if (argv[i][j] == 'a' || argv[i][j] == 'R' ||
				argv[i][j] == 'r' || argv[i][j] == 't' || argv[i][j] == 'l')
				insert_options(dir, argv[i][j]);
			else
				print_usage(argv[i][j]);
		}
	}
	else if (argv[i][0] != '-' || argv[1][0] != '-')
		return (i);
	if (ft_strcmp(argv[i], "-") == 0 && argc == 2)
		return (-1);
	else if (ft_strcmp(argv[i], "-") == 0)
	{
		ft_printf("./ft_ls: %s: No such file or directory\n", argv[i]);
		return (++i);
	}
	return (0);
}

int			parse_options(t_dir *dir, int argc, char **argv)
{
	size_t	i;
	size_t	j;
	int		arg_num_name;

	i = 0;
	j = 0;
	while (++i < (size_t)argc)
	{
		if ((arg_num_name = parse_options_body(dir, argv, i, argc)) > 0)
			return (arg_num_name);
		else if ((arg_num_name = parse_options_body(dir, argv, i, argc)) < 0)
			return (-1);
	}
	return (0);
}
