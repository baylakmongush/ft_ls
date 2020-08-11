/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:19:38 by Student           #+#    #+#             */
/*   Updated: 2020/08/11 13:16:46 by baylak           ###   ########.fr       */
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

typedef	struct		s_options
{
	int				l;
	int				R;
	int				a;
	int				r;
	int				t;
}					t_options;

typedef	struct		s_files
{
	struct s_files	*next;
	struct s_files	*prev;
	char			*name;
}					t_files;

typedef struct		s_dir
{
	char			**name_dir;
	t_options		options;
	t_files			*files;
	int				arg_num_name;
	DIR				*dirp;
	struct dirent	*dp;
	int				count;
	int				is_dir;
	struct stat 	mystat;
	char			PATH[1024 + 1];
}					t_dir;

int					parse_options(t_dir	*dir, int argc, char **argv);
void				print_usage(char str);
void				parse_folders(int argc, char **argv, int arg_num_name, t_dir *dir);
void				flags(t_dir *dir, int arg_num_name);

#endif