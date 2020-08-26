/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:19:38 by Student           #+#    #+#             */
/*   Updated: 2020/08/27 03:34:54 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H
# define SIX_MONTHS 15552000
# include <sys/types.h>
# include <sys/stat.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <dirent.h>
# include <string.h>
# include <errno.h>
# include <grp.h>
# include <sys/types.h>
# include <pwd.h>
# include "libft.h"
# include "limits.h"
# include <time.h>

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
	char			*file_name;
	struct stat 	mystat;
	long			ntime;
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
	char			PATH[1024 + 1];
}					t_dir;

int					parse_options(t_dir	*dir, int argc, char **argv);
void				print_usage(char str);
void				parse_folders(int argc, char **argv, int arg_num_name, t_dir *dir);
void				init_options(t_dir *dir);
t_files				*init_list_name(t_dir *dir);


t_files				*init_list(t_files *head, char *name);
void				add_elem(t_files **head, char *name);
void				insert_t_files(t_files **head_ptr, t_files *files);
void				reverse_list(t_files **head);
void				sorted_list(t_files **head);

void				print_dir(t_files *list, t_dir *dir, int flag);
void				print_file(t_files *list, t_dir *dir);
void				quicksort(t_files *head);
t_files				*lst_sort_ascii(t_files *lst);

t_files				*lst_sort_time(t_files *lst);

void 				display_attribute(char* name, char *file_name);
void				print_total(t_files *file_list);

#endif