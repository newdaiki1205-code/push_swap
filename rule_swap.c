/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rule_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:49:28 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 14:36:49 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa (t_list **a)
{
    t_list *current;
    
    if(!a || !(*a) || !(*a)->next)
        return;
    current = (*a)->next;
    (*a)->next = current->next;
    current->next = (*a);
    (*a) = current;
}

void sb (t_list **b)
{
    t_list *current;
    
    if(!b || !(*b) || !(*b)->next)
        return;
    current = (*b)->next;
    (*b)->next = current->next;
    current->next = (*b);
    (*b) = current;
}

void ss(t_list **a, t_list **b)
{
    sa(a);
    sb(b);
}
