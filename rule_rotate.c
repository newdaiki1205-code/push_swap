/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_rotate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:11:13 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/16 17:33:25 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ra(t_list **a)
{
    t_list *temp;
    t_list *last;
    int check;

    if(!a || !(*a) || !(*a)->next)
        return -1;
    last = find_last(*a);
    temp = *a;
    *a = (*a)->next;
    temp->next = last->next;
    last->next = temp;
    check = write(1, "ra\n", 3);
    return check;
}

void rb(t_list **b)
{
    t_list *temp;
    t_list *last;

    if(!b || !(*b) || !(*b)->next)
        return;
    last = find_last(*b);
    temp = *b;
    *b = (*b)->next;
    temp->next = last->next;
    last->next = temp;
}

void rr(t_list **a, t_list **b)
{
    ra(a);
    rb(b);
}

t_list *find_last(t_list *node)
{
    while(node->next)
        node = node->next;
    return node;   
}

