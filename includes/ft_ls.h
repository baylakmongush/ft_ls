/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/21 19:19:38 by Student           #+#    #+#             */
/*   Updated: 2020/08/10 21:28:05 by baylak           ###   ########.fr       */
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

typedef struct	s_dir
{
	int a;
}				t_dir;


int				parse(t_options *options, t_dir *dir, int argc, char **argv);

#endif