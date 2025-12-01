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

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct ps_list
{
	int				content;
	struct ps_list	*next;
}					my_list;

int					int_check(char **av);
int					is_it_integers(const char *s);
int					is_it_intmax(const char *s);
int					is_it_intmin(const char *s);
int					is_it_duplicated(my_list *head);
my_list				*make_list(char **av);
my_list				*make_newnode(char *av);
void				add_front(my_list **head, my_list *newnode);
void				free_list(my_list **head);

#endif