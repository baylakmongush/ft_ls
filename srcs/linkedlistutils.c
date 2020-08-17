/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linkedlistutils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/11 01:35:31 by baylak            #+#    #+#             */
/*   Updated: 2020/08/17 15:05:57 by baylak           ###   ########.fr       */
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
	if (*head != NULL)
		(*head)->prev = temp;
	(*head) = temp;
}

void		sorted_list(t_files **head)
{
	t_files	*current;
	t_files	*index;
	char	*temp;

	current = NULL;
	index = NULL;
	if (*head == NULL)
		return ;
	current = *head;
	while (current->next != NULL)
	{
		index = current->next;
		while (index != NULL)
		{
			if (current->name[0] > index->name[0])
			{
				temp = current->name;
				current->name = index->name;
				index->name = temp;
			}
			index = index->next;
		}
		current = current->next;
	}
}

void		reverse_list(t_files **head)
{
    t_files *temp;
    t_files *current;

	temp = NULL;
	current = *head;
    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;           
        current = current->prev;
    }  
    if (temp != NULL)
        *head = temp->prev;
}