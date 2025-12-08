/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 14:47:18 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/01 19:39:37 by dshirais         ###   ########.fr       */
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
	long value;
	int order;
}	sort_array;

typedef struct second_array
{
	long value;
	int rank;
} map_array;

// int					int_check(char **av);
// int					is_it_integers(const char *s);
// int					is_it_intmax(const char *s);
// int					is_it_intmin(const char *s);
sort_array *make_array(char **av, int size);
long 				int_error_atoi(char *av);
void quick_sort(sort_array *array, int left, int right);
void	is_it_duplicated(sort_array **array, int size);
map_array *make_look_up(sort_array *array, int size);
t_list	*make_list(map_array *look_up, int size);
t_list	*make_newnode(map_array look_up);
void				add_front(t_list **head, t_list *newnode);
void				free_list(t_list **head);

#endif