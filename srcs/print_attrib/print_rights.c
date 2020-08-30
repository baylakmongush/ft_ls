/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rights.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:06:38 by baylak            #+#    #+#             */
/*   Updated: 2020/08/30 13:04:21 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_type(struct stat buf)
{
	if (S_ISLNK(buf.st_mode))
		ft_printf("l");
	else if (S_ISREG(buf.st_mode))
		ft_printf("-");
	else if (S_ISDIR(buf.st_mode))
		ft_printf("d");
	else if (S_ISCHR(buf.st_mode))
		ft_printf("c");
	else if (S_ISBLK(buf.st_mode))
		ft_printf("b");
	else if (S_ISFIFO(buf.st_mode))
		ft_printf("f");
	else if (S_ISSOCK(buf.st_mode))
		ft_printf("s");
}

void	print_own_rights(struct stat buf)
{
	if (buf.st_mode & S_IRUSR)
		ft_printf("r");
	else
		ft_printf("-");
	if (buf.st_mode & S_IWUSR)
		ft_printf("w");
	else
		ft_printf("-");
	if (buf.st_mode & S_IXUSR)
		ft_printf("x");
	else
		ft_printf("-");
}

void	print_group_per(struct stat buf)
{
	if (buf.st_mode & S_IRGRP)
		ft_printf("r");
	else
		ft_printf("-");
	if (buf.st_mode & S_IWGRP)
		ft_printf("w");
	else
		ft_printf("-");
	if (buf.st_mode & S_IXGRP)
		ft_printf("x");
	else
		ft_printf("-");
}

void	print_peop_rights(struct stat buf)
{
	if (buf.st_mode & S_IROTH)
		ft_printf("r");
	else
		ft_printf("-");
	if (buf.st_mode & S_IWOTH)
		ft_printf("w");
	else
		ft_printf("-");
	if (buf.st_mode & S_IXOTH)
		ft_printf("x");
	else
		ft_printf("-");
}
