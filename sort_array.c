/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:03:05 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/01 19:39:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

sort_array *make_array(char **av)
{
    int size;
    int i;
    sort_array *array;

    size = 0;
    while(av[size + 1])
        size++;
    array = (sort_array*)malloc(sizeof(sort_array) * (size));
    if(!array)
        return NULL;
    i = 0;
    while(i < size)
    {
        array[i].order = i + 1;
        array[i].value = int_error_atoi(av[i + 1]);
        if(array[i].value > 2147483647 || array[i].value < -2147483648)
            return (free(array), NULL);
        i++;
    }
    quick_sort(array, 0, size - 1);
    return array;
}

long int_error_atoi(char *av)
{
	long res;
	int sign;
	int i;

	res = 0;
	sign = 1;
	i = 0;
	while(av[i])
	{
		if (av[i]== '-')
		{
			sign *= -1;
			i++;
		}
		if(!(av[i] >= '0' && av[i] <= '9'))
			return (-2147483649);
		res = res * 10 + (av[i] - '0');
		i++;
	}
	return (res * sign);
}

void quick_sort(sort_array *array, int left, int right) //dont forget free array when error
{
    sort_array base;
    int i;
    int j;
    sort_array temp;
    
    base = array[left];
    i = left;
    j = right;
    if(left < right)
    {
        while(1)
        {
            while(i <= j && array[i + 1].value < base.value)
                i++;
            while(i <= j && array[j].value > base.value)
                j--;
            if(i >= j)
                break;
            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
        array[left] = array[j];
        array[j] = base;
        quick_sort(array, left, j - 1);
        quick_sort(array, j + 1, right);
    }
}