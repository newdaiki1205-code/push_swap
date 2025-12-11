/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_reverse_rotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:38:49 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 15:52:16 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_list **a)
{
    t_list *pre_last;
    t_list *last;

    if(!a || !(*a) || !(*a)->next)
        return;
    last = find_last(*a);
    pre_last = find_pre_last(*a);
    pre_last->next = last->next;
    last->next = *a;
    *a = last;
}

void rrb(t_list **b)
{
    t_list *pre_last;
    t_list *last;

    if(!b || !(*b) || !(*b)->next)
        return;
    last = find_last(*b);
    pre_last = find_pre_last(*b);
    pre_last->next = last->next;
    last->next = *b;
    *b = last;
}

void rrr(t_list **a, t_list **b)
{
    rra(a);
    rrb(b);
}

t_list *find_pre_last(t_list *node)
{
    t_list *current;
    t_list *prev;

    current = node;
    prev = NULL;
    while(current->next)
    {
        prev = current;
        current = current->next;
    }
    return prev;
}