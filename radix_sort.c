/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:10:30 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 15:00:05 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void radix_sort(t_list **a, t_list **b, int size)
{
    int k;
    int i;
    int counter;

    k = 0;
    i = 0;
    while (size >> k != 0)
        k++;
    while(i < k)
    {
        counter = 0;
        while(counter < size)
        {
            if((*a)->rank >> i & 1)
            {
                ra(a);
                write(1, "ra\n", 3);
            }
            else
            {
                pb(a, b);
                write(1, "pb\n", 3);
            }
            counter++;
        }
        while(*b)
            pa(a, b);
        i++;   
    }
}
