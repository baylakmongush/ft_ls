/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:19:38 by Student           #+#    #+#             */
/*   Updated: 2020/08/11 01:22:46 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include "libft.h"

typedef	struct	s_options
{
	int			l;
	int			R;
	int			a;
	int			r;
	int			t;
}				t_options;

typedef	struct		s_files
{
	struct s_files	*next;
	char			*name;
}				t_files;

typedef struct	s_dir
{
	char		**name_dir;
	t_files		*files;
}				t_dir;

int				parse_options(t_options *options, int argc, char **argv);
void			print_usage(char str);
void			parse_folders(int argc, char **argv, int arg_num_name, t_dir *dir);

#endif