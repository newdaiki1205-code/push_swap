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

// int	main(void)
// {
// 	sort_array *array;
// 	char *av[] = {"3", "2", "1", NULL};

// 	array = make_array(av);
// 	if (!array)
// 		return (write(2, "Error\n", 6), -1);
// 	int i = 0;
// 	while(i < 4)
// 	{
// 		printf("%ld ", array[i].value);
// 		i++;
// 	}
	
// 	return (0);
// }


int	main(int ac, char **av)
{
	sort_array *array;
	//my_list *head;

	if (ac < 2)
		NULL;
	array = make_array(av);
	if (!array)
		return (write(2, "Error\n", 6), -1);
	// head = NULL;
	// head = make_list(av);
	int i = 0;
	while(i < 10)
	{
		printf("%ld ", array[i].value);
		i++;
	}
	
	return (0);
}