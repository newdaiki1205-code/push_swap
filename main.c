/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:45:32 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 15:46:49 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "sort_array.c"
// #include "list_handling.c"
// #include "rule_push.c"
#include <stdio.h>

int	main(int ac, char **av)
{
	sort_array *array;
	map_array *look_up;
	int size;
	t_list *a;
	t_list *b;

	if (ac < 2)
		return (write(1, "\n", 1), 1);
	size = ac - 1;
	array = make_array(av, size);
	if (!array)
		return (write(2, "Error\n", 6), -1);
	look_up = make_look_up(array, size);
	if (!look_up)
		return (free(array), write(2, "Error\n", 6), -1);
	a = make_stack_a(look_up, size);
	if (!a)
		return (free(look_up), write(2, "Error\n", 6), -1);
	b = NULL;
	rra(&a);
	int i = 0;
	while (i < 3)
	{
		printf("%ld ", a->content);
		printf("%d\n", a->rank);
		a = a->next;
		i++;
	}
	// printf("\n");
	// i = 0;
	// while (i < 1)
	// {
	// 	printf("%ld ", b->content);
	// 	printf("%d\n", b->rank);
	// 	b = b->next;
	// 	i++;
	// }

	return (0);
}
