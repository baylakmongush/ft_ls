/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:24:05 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/27 01:01:29 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_files	*ft_swap(t_files *p1, t_files *p2)
{
	p1->next = p2->next;
	p2->next = p1;
	return (p2);
}

/* t_files	*last_elem(t_files *head)
{
	while (head && head->next)
		head = head->next;
	return (head);
}

t_files	*divide(t_files *head, t_files *last)
{
	t_files	*j;
	t_files	*i;

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
			ft_swap(&(i), &(j));
		}
		j = j->next;
	}
	if (i == NULL)
		i = head;
	else
		i = i->next;
	ft_swap(&(i), &(last));
	return (i);
}

void	requicksort(t_files *head, t_files *last)
{
	t_files *div;

	if (last != NULL && head != last && head != last->next)
	{
		div = divide(head, last);
		requicksort(head, div->prev);
		requicksort(div->next, last);
	}
}

void	quicksort(t_files *head)
{
	t_files	*last;

	last = last_elem(head);
	requicksort(head, last);
}*/


t_files	*lst_sort_ascii(t_files *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
		lst = ft_swap(lst, lst->next);
	lst->next = lst_sort_ascii(lst->next);
	if (lst->next && ft_strcmp(lst->name, lst->next->name) > 0)
	{
		lst = ft_swap(lst, lst->next);
		lst->next = lst_sort_ascii(lst->next);
	}
	return (lst);
}

t_files	*lst_sort_time(t_files *lst)
{
	if (!lst)
		return (NULL);
	if (lst->next && (lst->mystat.st_mtime < lst->next->mystat.st_mtime))
		lst = ft_swap(lst, lst->next);
	else if (lst->next && lst->mystat.st_mtime == lst->next->mystat.st_mtime)
		if (lst->next && (lst->ntime < lst->next->ntime))
			lst = ft_swap(lst, lst->next);
	lst->next = lst_sort_time(lst->next);
	if (lst->next && (lst->mystat.st_mtime < lst->next->mystat.st_mtime))
	{
		lst = ft_swap(lst, lst->next);
		lst->next = lst_sort_time(lst->next);
	}
	else if (lst->next && lst->mystat.st_mtime == lst->next->mystat.st_mtime)
	{
		if (lst->next && (lst->file_name > lst->next->file_name))
		{
			lst = ft_swap(lst, lst->next);
			lst->next = lst_sort_time(lst->next);
		}
	}
	return (lst);
}
