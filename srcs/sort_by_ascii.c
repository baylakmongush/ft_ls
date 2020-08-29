/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_ascii.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:24:05 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/29 13:09:54 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static t_files	*last_elem(t_files *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

static t_files	*divide(t_files *head, t_files *last)
{
	t_files		*j;
	t_files		*i;

	i = head->prev;
	j = head;
	while (j != last)
	{
		if (ft_strcmp(j->file_name, last->file_name) <= 0)
		{
			if (i == NULL)
				i = head;
			else
				i = i->next;
			swap(i, j);
		}
		j = j->next;
	}
	if (i == NULL)
		i = head;
	else
		i = i->next;
	swap(i, last);
	return (i);
}

static void		requicksort(t_files *head, t_files *last)
{
	t_files		*div;

	if (last != NULL && head != last && head != last->next)
	{
		div = divide(head, last);
		requicksort(head, div->prev);
		requicksort(div->next, last);
	}
}

void			quicksort(t_files *head)
{
	t_files		*last;

	last = last_elem(head);
	requicksort(head, last);
}
