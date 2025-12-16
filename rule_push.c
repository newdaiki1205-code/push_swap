/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 14:10:30 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/16 18:00:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int pb(t_list **a, t_list **b)
{
	t_list *temp;
    int check;

    if(!a || !(*a))
        return -1;
    temp = *a;
    *a = temp->next;
    temp->next = *b;
    (*b) = temp;
    check = write(1, "pb\n", 3);
    return check;
}

int pa(t_list **a, t_list **b)
{
	t_list *temp;
    int check;

    if(!b || !(*b))
        return -1;
    temp = *b;
    *b = temp->next;
    temp->next = *a;
    (*a) = temp;
    check = write(1, "pa\n", 3);
    return check;
}


