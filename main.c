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
	int *look_up;

	if (ac < 2)
		NULL;
	array = make_array(av);
	if (!array)
		return (write(2, "Error\n", 6), -1);
	look_up = make_look_up(av, array);
	if (!look_up)
		return (write(2, "Error\n", 6), -1);
	int i = 0;
	while(i < 4)
	{
		printf("%d ", look_up[i]);
		i++;
	}
	
	return (0);
}