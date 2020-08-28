/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/25 15:24:05 by poatmeal          #+#    #+#             */
/*   Updated: 2020/08/28 14:46:30 by baylak           ###   ########.fr       */
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

void		swap(t_files *a, t_files *b)
{
	char *file_name;
	char *name;
	struct stat tmp;

	name = NULL;
	file_name = NULL;
	file_name = a->file_name;
	name = a->name;
	tmp = a->mystat;
	a->file_name = b->file_name;
	a->name = b->name;
	a->mystat = b->mystat;
	b->name = name;
	b->file_name = file_name;
	b->mystat = tmp;
}

int			cmp_times(long t1, long t2, char *name1, char *name2)
{
	return (t1 == t2 ? ft_strcmp(name1, name2) : t1 - t2);
}

t_files			*sort_time(t_files *path, int reverse)
{
	t_files		*begin;
	t_files		*tmp;
	struct stat tstat;
	struct stat pstat;

	reverse = 1;
	tmp = NULL;
	begin = path;
	while (path)
	{
		tmp = path->next;
		while (tmp)
		{
			lstat(path->name, &pstat);
			lstat(tmp->name, &tstat);
			if (cmp_times(pstat.st_mtimespec.tv_sec, tstat.st_mtimespec.tv_sec, path->file_name,
						tmp->file_name) < 0)
				swap(path, tmp);
			else if (cmp_times(pstat.st_mtimespec.tv_sec, tstat.st_mtimespec.tv_sec, path->file_name,
						tmp->file_name) == 0)
				lst_sort_ascii(path);
			tmp = tmp->next;
		}
		path = path->next;
	}
	return (begin);
}
