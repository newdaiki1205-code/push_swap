/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 18:17:10 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 20:58:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_choice(t_list **a, t_list **b, int size)
{
	int	check;

	if (size == 2)
		check = sa(a);
	if (size == 3)
		check = sort_three(a);
	if (size > 3 && size < 6)
		check = medi_sort(a, b, size);
	else
		check = radix_sort(a, b, size);
	if (check < 0)
		return (free_list(a), free_list(b), -1);
	return (check);
}

int	sort_three(t_list **a)
{
	int	check;

	if ((*a)->rank == 0)
		check = case_zero(a);
	else if ((*a)->rank == 1)
		check = case_one(a);
	else if ((*a)->rank == 2)
		check = case_two(a);
	else
		check = -1;
	return (check);
}

int	case_zero(t_list **a)
{
	if (!zero_sort_check(*a))
		return (0);
	if (sa(a) < 0 || ra(a) < 0)
		return (-1);
	else
		return (0);
}

int	case_one(t_list **a)
{
	if ((*a)->next->rank == 0 && sa(a) >= 0)
		return (0);
	else if ((*a)->next->rank == 2 && rra(a) >= 0)
		return (0);
	else
		return (-1);
}

int	case_two(t_list **a)
{
	if ((*a)->next->rank == 0 && ra(a) >= 0)
		return (0);
	else if ((*a)->next->rank == 1 && (ra(a) >= 0 && sa(a) >= 0))
		return (0);
	else
		return (-1);
}
