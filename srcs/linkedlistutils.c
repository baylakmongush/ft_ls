/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:35:31 by baylak            #+#    #+#             */
/*   Updated: 2020/08/28 08:52:56 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		add_elem(t_files **head, char *name)
{
	t_files	*temp;

	temp = (t_files*)malloc(sizeof(t_files));
	temp->next = (*head);
	temp->prev = NULL;
	temp->name = name;
	temp->file_name = name;
	if (*head != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

void		reverse_list(t_files **head)
{
	t_files	*curr; 
    t_files	*prev;
    t_files	*next;

	curr = *head;
	prev = NULL;
	next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = prev;
        curr->prev = next;
        prev = curr;
        curr = next;
    }
    *head = prev;
}
