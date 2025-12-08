/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:45:32 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/01 19:39:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//#include "sort_array.c"
#include <stdio.h>

int	main(int ac, char **av)
{
	sort_array *array;
	map_array *look_up;
	int size;
	t_list *a;

	if (ac < 2)
		NULL;
	size = ac - 1;
	array = make_array(av, size);
	if (!array)
		return (write(2, "Error\n", 6), -1);
	look_up = make_look_up(array, size);
	if (!look_up)
		return (free(array), write(2, "Error\n", 6), -1);
	a = make_list(look_up, size);
	if (!a)
		return (free(look_up), write(2, "Error\n", 6), -1);
	int i = 0;
	while(i < 4)
	{
		printf("%ld ", a->content);
		printf("%d\n", a->rank);
		a = a->next;
		i++;
	}
	
	return (0);
}