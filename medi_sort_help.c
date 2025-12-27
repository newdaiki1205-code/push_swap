/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medi_sort_help.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 20:54:51 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 20:55:27 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	back_to_a(t_list **a, t_list **b)
{
	int	check;

	while (*b)
	{
		check = pa(a, b);
		if (check < 0)
			return (-1);
	}
	return (0);
}

int	zero_sort_check(t_list *a)
{
	while (a->next)
	{
		if (a->rank > a->next->rank)
			return (1);
		a = a->next;
	}
	return (0);
}
