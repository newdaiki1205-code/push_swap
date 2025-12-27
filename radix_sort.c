/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:10:30 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 19:18:33 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	radix_sort(t_list **a, t_list **b, int size)
{
	int	k;
	int	i;
	int	counter;
	int	check;

	k = byte_count(size);
	i = 0;
	while (i < k)
	{
		counter = 0;
		while (counter < size)
		{
			if ((*a)->rank >> i & 1)
				check = ra(a);
			else
				check = pb(a, b);
			if (check < 0)
				return (-1);
			counter++;
		}
		if (before_next_sort(a, b) < 0)
			return (-1);
		i++;
	}
	return (0);
}

int	before_next_sort(t_list **a, t_list **b)
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

int	byte_count(int size)
{
	int	k;

	k = 0;
	while (size >> k != 0)
		k++;
	return (k);
}
