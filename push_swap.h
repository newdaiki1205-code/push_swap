/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:47:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/27 20:53:04 by dshirais         ###   ########.fr       */
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
}					t_sortarray;

typedef struct second_array
{
	long			value;
	int				rank;
}					t_maparray;

t_sortarray			*make_array(char **av, int size);
long				int_error_atoi(char *av);
void				quick_sort(t_sortarray *array, int left, int right);
void				quick_swap(t_sortarray *array, int i, int j);
void				is_it_duplicated(t_sortarray **array, int size);
t_maparray			*make_look_up(t_sortarray *array, int size);
int					is_it_sorted(t_maparray *look_up, int size);
t_list				*make_stack_a(t_maparray *look_up, int size);
t_list				*make_newnode(t_maparray look_up);
void				add_back(t_list **head, t_list *newnode);
void				free_list(t_list **head);
int					sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);
int					pb(t_list **a, t_list **b);
int					pa(t_list **a, t_list **b);
int					ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **a, t_list **b);
int					rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **a, t_list **b);
t_list				*find_last(t_list *a);
t_list				*find_pre_last(t_list *node);
int					radix_sort(t_list **a, t_list **b, int size);
int					before_next_sort(t_list **a, t_list **b);
int					byte_count(int size);
int					sort_choice(t_list **a, t_list **b, int size);
int					sort_three(t_list **a);
int					case_zero(t_list **a);
int					case_one(t_list **a);
int					case_two(t_list **a);
int					medi_sort(t_list **a, t_list **b, int size);
int					prepare_op(t_list **a, t_list **b, int size);
int					to_up(t_list **a, int smallest);
int					to_down(t_list **a, int smallest, int size);
int					find_smallest(t_list *a, int index);
int					back_to_a(t_list **a, t_list **b);
int					zero_sort_check(t_list *a);

#endif
