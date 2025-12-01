/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_handling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:05:25 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/01 19:44:55 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

my_list	*make_newnode(char *av)
{
	my_list	*newnode;

	newnode = (my_list *)malloc(sizeof(my_list));
	if (!newnode)
		return (NULL);
	newnode->content = ft_atoi(av);
	newnode->next = NULL;
	return (newnode);
}

void	add_front(my_list **head, my_list *newnode)
{
	if (!head || !newnode)
		return ;
	newnode->next = *head;
	*head = newnode;
}

void	free_list(my_list **head)
{
	my_list	*temp;

	while (*head)
	{
		temp = *head;
		*head = (*head)->next;
		free(temp);
	}
}

my_list	*make_list(char **av)
{
	int		i;
	my_list	*head;
	my_list	*newnode;

	head = NULL;
	i = 1;
	if (int_check(av))
		return (NULL);
	while (av[i])
	{
		newnode = make_newnode(av[i]);
		if (!newnode)
			return (free_list(&head), NULL);
		add_front(&head, newnode);
		i++;
	}
	if (is_it_duplicated(head))
		return (free_list(&head), NULL);
	return (head);
}
