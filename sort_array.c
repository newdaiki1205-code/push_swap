/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:36:13 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/16 19:01:34 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

sort_array	*make_array(char **av, int size)
{
	int			i;
	sort_array	*array;

	array = (sort_array *)malloc(sizeof(sort_array) * (size));
	if (!array)
		return (NULL);
	i = 0;
	while (i < size)
	{
		array[i].order = i;
		array[i].value = int_error_atoi(av[i + 1]);
		if (array[i].value > 2147483647 || array[i].value < -2147483648)
			return (free(array), NULL);
		i++;
	}
	//i = 0;
	// while(i < size)
	// {
	// 	if(array[i].value > array[i + 1].value)
	// 		break;
	// 	i++; 
	// }
	// if(i == size - 1)
	// 	return NULL;
	quick_sort(array, 0, size - 1);
	is_it_duplicated(&array, size);
	return (array);
}

long	int_error_atoi(char *av)
{
	long	res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
		{
			sign *= -1;
			i++;
		}
		if (!(av[i] >= '0' && av[i] <= '9'))
			return (-2147483649);
		res = res * 10 + (av[i] - '0');
		i++;
	}
	return (res * sign);
}

void	quick_sort(sort_array *array, int left, int right)
{
	sort_array	base;
	int			i;
	int			j;

	base = array[left];
	i = left;
	j = right + 1;
	if (left < right)
	{
		while (1)
		{
			while (i < right && array[++i].value < base.value)
				;
			while (j > left && array[--j].value > base.value)
				;
			if (i >= j)
				break ;
			quick_swap(array, i, j);
		}
		array[left] = array[j];
		array[j] = base;
		quick_sort(array, left, j - 1);
		quick_sort(array, j + 1, right);
	}
}

void quick_swap(sort_array *array, int i, int j)
{
	sort_array temp;
	
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void	is_it_duplicated(sort_array **array, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < size)
	{
		if ((*array)[i].value == (*array)[j].value)
		{
			free(*array);
			*array = NULL;
			return ;
		}
		i++;
		j++;
	}
}

map_array	*make_look_up(sort_array *array, int size)
{
	map_array *look_up;
	int rank;

	look_up = (map_array *)malloc(sizeof(map_array) * size);
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
