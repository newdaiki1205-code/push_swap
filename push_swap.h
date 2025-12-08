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

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}					my_list;

typedef struct initial_array
{
	long value;
	int order;
}	sort_array;

// int					int_check(char **av);
// int					is_it_integers(const char *s);
// int					is_it_intmax(const char *s);
// int					is_it_intmin(const char *s);
sort_array 			*make_array(char **av);
long 				int_error_atoi(char *av);
void quick_sort(sort_array *array, int left, int right);
void	is_it_duplicated(sort_array **array, int size);
int *make_look_up(char **av, sort_array *array);
my_list				*make_list(char **av);
my_list				*make_newnode(char *av);
void				add_front(my_list **head, my_list *newnode);
void				free_list(my_list **head);

#endif