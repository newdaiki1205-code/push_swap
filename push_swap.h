/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:47:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/11 15:53:31 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			content;
	int				rank;
	struct s_list	*next;
}					t_list;

typedef struct initial_array
{
	long			value;
	int				order;
}					sort_array;

typedef struct second_array
{
	long			value;
	int				rank;
}					map_array;

sort_array			*make_array(char **av, int size);
long				int_error_atoi(char *av);
void				quick_sort(sort_array *array, int left, int right);
void				is_it_duplicated(sort_array **array, int size);
map_array			*make_look_up(sort_array *array, int size);
t_list				*make_stack_a(map_array *look_up, int size);
t_list				*make_newnode(map_array look_up);
void				add_front(t_list **head, t_list *newnode);
void				free_list(t_list **head);
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
void				pb(t_list **a, t_list **b);
void				pa(t_list **a, t_list **b);
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
t_list				*find_last(t_list *a);
t_list				*find_pre_last(t_list *node);
void radix_sort(t_list **a, t_list **b, int size);

#endif