/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:45:32 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/16 19:15:50 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// #include "sort_array.c"
// #include "list_handling.c"
// #include "rule_push.c"
#include <stdio.h>

// int	main(int ac, char **av)
// {
// 	sort_array *array;
// 	map_array *look_up;
// 	int size;
// 	t_list *a;
// 	t_list *b;

// 	if (ac < 2)
// 		return (write(1, "\n", 1), 1);
// 	size = ac - 1;
// 	array = make_array(av, size);
// 	if (!array)
// 		return (write(2, "Error\n", 6), -1);
// 	look_up = make_look_up(array, size);
// 	if (!look_up)
// 		return (free(array), write(2, "Error\n", 6), -1);
// 	a = make_stack_a(look_up, size);
// 	if (!a)
// 		return (free(look_up), write(2, "Error\n", 6), -1);
// 	b = NULL;
// 	radix_sort(&a, &b, size);
// 	int i = 0;
// 	while (i < size)
// 	{
// 		printf("%ld ", a->content);
// 		printf("%d\n", a->rank);
// 		a = a->next;
// 		i++;
// 	}
// 	if(a)
// 		free_list(&a);
// 	if(b)
// 		free_list(&b);
// 	return (0);
// }

int	is_it_sorted(map_array *look_up, int size)
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

int	main(int ac, char **av)
{
	sort_array	*array;
	map_array	*look_up;
	//int 		check;
	t_list		*a;
	t_list		*b;

	if (ac < 2)
		return (write(1, "\n", 1), 1);
	array = make_array(av, ac - 1);
	if (!array)
		return (write(2, "Error\n", 6), -1);
	look_up = make_look_up(array, ac - 1);
	if (!look_up)
		return (free(array), write(2, "Error\n", 6), -1);
	if (!is_it_sorted(look_up, ac - 1))
		return (free(look_up), 1);
	a = make_stack_a(look_up, ac - 1);
	if (!a)
		return (free(look_up), write(2, "Error\n", 6), -1);
	b = NULL;
	// check = radix_sort(&a, &b, ac - 1);
	// if(check < 0)
	// 	return 1;
	if(radix_sort(&a, &b, ac -1) < 0)
		return 1;
	return (free_list(&a), free_list(&b), 0);
}
