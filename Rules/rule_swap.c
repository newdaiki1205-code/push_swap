/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:49:28 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 20:57:17 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_list **a)
{
	t_list	*current;
	int		check;

	if (!a || !(*a) || !(*a)->next)
		return (-1);
	current = (*a)->next;
	(*a)->next = current->next;
	current->next = (*a);
	(*a) = current;
	check = write(1, "sa\n", 3);
	return (check);
}

void	sb(t_list **b)
{
	t_list	*current;

	if (!b || !(*b) || !(*b)->next)
		return ;
	current = (*b)->next;
	(*b)->next = current->next;
	current->next = (*b);
	(*b) = current;
}

void	ss(t_list **a, t_list **b)
{
	sa(a);
	sb(b);
}
