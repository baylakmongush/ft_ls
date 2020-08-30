/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_time.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 12:08:57 by baylak            #+#    #+#             */
/*   Updated: 2020/08/30 13:07:20 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		print_time(time_t mtime)
{
	char	*str_time;
	time_t	ct;

	ct = time(NULL);
	if ((str_time = ctime(&mtime)) == NULL)
		return ;
 	ft_printf("%3.3s ", str_time + 4);
	ft_printf("%2.2s ", str_time + 8);
	if (mtime < 15778800 || mtime > ct)
		ft_printf("%5.4s ", str_time + 20);
	else
		ft_printf("%5.5s ", str_time + 11);
}
