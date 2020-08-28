/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 00:01:45 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 03:52:49 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_usage(char str)
{
	ft_printf("ls: illegal option -- %c\n", str);
	ft_printf("usage: ls [-alRrt] [file ...]\n");
	exit(1);
}
