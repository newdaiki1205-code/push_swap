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

void pb(t_list **a, t_list **b)
{
	t_list *temp;

    if(!a || !(*a))
        return;
    temp = *a;
    *a = temp->next;
    temp->next = *b;
    (*b) = temp;
}

void pa(t_list **a, t_list **b)
{
	t_list *temp;

    if(!b || !(*b))
        return;
    temp = *b;
    *b = temp->next;
    temp->next = *a;
    (*a) = temp;
}


