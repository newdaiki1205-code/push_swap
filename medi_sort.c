/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medi_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 19:22:40 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 20:57:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	medi_sort(t_list **a, t_list **b, int size)
{
	t_list	*temp;
	int		check;
	int		modify;

	if (prepare_op(a, b, size) < 0)
		return (-1);
	temp = *a;
	if (size == 5)
		modify = 2;
	else
		modify = 1;
	while (temp)
	{
		temp->rank -= modify;
		temp = temp->next;
	}
	check = sort_three(a);
	if (check < 0)
		return (-1);
	if (back_to_a(a, b) < 0)
		return (-1);
	return (0);
}

int	prepare_op(t_list **a, t_list **b, int size)
{
	int	smallest;
	int	check;
	int	i;

	i = 0;
	while (size > 3)
	{
		smallest = find_smallest(*a, i);
		if (smallest < size / 2)
			check = to_up(a, smallest);
		else
			check = to_down(a, smallest, size);
		if (check < 0)
			return (-1);
		if (pb(a, b) < 0)
			return (-1);
		size--;
		i++;
	}
	return (0);
}

int	to_up(t_list **a, int smallest)
{
	while (smallest != 0)
	{
		if (ra(a) < 0)
			return (-1);
		smallest--;
	}
	return (0);
}

int	to_down(t_list **a, int smallest, int size)
{
	while (smallest != size)
	{
		if (rra(a) < 0)
			return (-1);
		smallest++;
	}
	return (0);
}

int	find_smallest(t_list *a, int index)
{
	int	i;
	int	target;

	i = 0;
	if (index == 0)
		target = 0;
	else
		target = 1;
	while (a)
	{
		if (a->rank == target)
			break ;
		i++;
		a = a->next;
	}
	return (i);
}
