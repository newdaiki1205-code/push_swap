/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_array.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 14:52:49 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 15:01:16 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_maparray	*make_look_up(t_sortarray *array, int size)
{
	t_maparray	*look_up;
	int			rank;

	look_up = (t_maparray *)malloc(sizeof(t_maparray) * size);
	if (!look_up)
		return (NULL);
	rank = 0;
	while (rank < size)
	{
		look_up[array[rank].order].value = array[rank].value;
		look_up[array[rank].order].rank = rank;
		rank++;
	}
	free(array);
	return (look_up);
}

int	is_it_sorted(t_maparray *look_up, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (look_up[i].rank > look_up[i + 1].rank)
			return (1);
		i++;
	}
	return (0);
}
