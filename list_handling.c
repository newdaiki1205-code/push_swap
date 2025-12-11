/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:05:25 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 14:20:52 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*make_newnode(map_array look_up)
{
	t_list	*newnode;

	newnode = (t_list *)malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = look_up.value;
	newnode->rank = look_up.rank;
	newnode->next = NULL;
	return (newnode);
}

void	add_front(t_list **head, t_list *newnode)
{
	if (!head || !newnode)
		return ;
	newnode->next = *head;
	*head = newnode;
}

void	free_list(t_list **head)
{
	t_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

t_list	*make_stack_a(map_array *look_up, int size)
{
	int i;
	t_list *head;
	t_list *newnode;

	head = NULL;
	i = 0;
	while (i < size)
	{
		newnode = make_newnode(look_up[i]);
		if (!newnode)
			return (free_list(&head), NULL);
		add_front(&head, newnode);
		i++;
	}
	free(look_up);
	return (head);
}

