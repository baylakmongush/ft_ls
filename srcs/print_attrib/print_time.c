/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:08:57 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 12:35:40 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_time(time_t mtime)
{
	char	*str_time;
	char	*pointer;
	char	*next_point;
	time_t	ct;

	ct = time(NULL);
	if ((str_time = ctime(&mtime)) == NULL)
		return ;
	pointer = str_time + 4;
	next_point = str_time + 10;
	*next_point = '\0';
	ft_printf(" %-2s", pointer);
	pointer = (mtime + 15778800 < ct) ?
	str_time + 20 : str_time + 11;
	next_point = (mtime + 15778800 < ct) ?
	str_time + 24 : (next_point = str_time + 16);
	if (mtime + 15778800 < ct)
		ft_putchar(' ');
	*next_point = '\0';
	ft_printf(" %s", pointer);
}
