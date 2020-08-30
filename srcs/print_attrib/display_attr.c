/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_attr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:07:57 by baylak            #+#    #+#             */
/*   Updated: 2020/08/30 13:07:57 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			display_attr(char *name, char *file_name, mode_t mode)
{
	struct stat	buf;

	if (lstat(name, &buf) == -1)
	{
		perror("lstat");
		return ;
	}
	print_file_type(buf);
	print_own_rights(buf);
	print_group_per(buf);
	print_peop_rights(buf);
	display_ext_attr(name);
	print_user_group(buf);
	ft_printf("%4lld ", buf.st_size);
	print_time(buf.st_mtime);
	link_print(name, file_name, mode);
}
