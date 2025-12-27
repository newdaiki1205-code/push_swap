/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_array.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 12:36:13 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 15:00:01 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_sortarray	*make_array(char **av, int size)
{
	int			i;
	t_sortarray	*array;

	array = (t_sortarray *)malloc(sizeof(t_sortarray) * (size));
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

void	quick_sort(t_sortarray *array, int left, int right)
{
	t_sortarray	base;
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

void	quick_swap(t_sortarray *array, int i, int j)
{
	t_sortarray	temp;

	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

void	is_it_duplicated(t_sortarray **array, int size)
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
