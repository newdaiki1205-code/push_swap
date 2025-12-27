/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:45:32 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 18:56:53 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_sortarray	*array;
	t_maparray	*look_up;
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
	if (sort_choice(&a, &b, ac - 1) < 0)
		return (1);
	return (free_list(&a), free_list(&b), 0);
}
