/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: baylak <baylak@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/29 11:37:59 by baylak            #+#    #+#             */
/*   Updated: 2020/08/29 11:38:22 by baylak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_clear_list(t_files **head)
{
	t_files *curr;
	t_files	*temp;

	if (*head != NULL)
	{
		curr = (*head)->next;
		while (curr != NULL && curr != *head)
		{
			temp = curr;
			curr = curr->next;
			free(temp->file_name);
			temp->file_name = NULL;
			free(temp->name);
			temp->name = NULL;
			free(temp);
		}
		free(*head);
		*head = NULL;
	}
}