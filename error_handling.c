/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/01 17:03:05 by dshirais          #+#    #+#             */
/*   Updated: 2025/12/01 19:39:37 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_it_integers(const char *s)
{
	int	len;
	int	len_check;

	len = ft_strlen(s);
	len_check = 0;
	if (*s == '-')
		len_check++;
	while (s[len_check] >= '0' && s[len_check] <= '9')
		len_check++;
	if (len != len_check)
		return (1);
	return (0);
}

int	is_it_intmax(const char *s)
{
	char	*max;
	int		i;

	max = "2147483647";
	i = 0;
	if (ft_strlen(s) < 10)
		return (0);
	if (ft_strlen(s) > 10)
		return (1);
	while (i < ft_strlen(s))
	{
		if (s[i] > max[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_it_intmin(const char *s)
{
	char	*min;
	int		i;
	int		j;

	min = "-2147483648";
	i = 0;
	if (s[0] != '-')
		return (0);
	if (ft_strlen(s) < 11)
		return (0);
	if (ft_strlen(s) > 11)
		return (1);
	while (i < ft_strlen(s))
	{
		if (s[i] > min[i])
			return (1);
		i++;
	}
	return (0);
}

int	int_check(char **av)
{
	int		i;
	my_list	*head;
	my_list	*newnode;

	i = 1;
	while (av[i])
	{
		if (av[i][0] != '1' && is_it_integers(av[i]))
			return (1);
		if (is_it_intmin(av[i]) || is_it_intmax(av[i]))
			return (1);
		i++;
	}
	return (0);
}

int	is_it_duplicated(my_list *head)
{
    my_list *currentnode;
    my_list *nextnode;

    currentnode = head;
    while(currentnode)
    {
        nextnode = head->next;
        while(nextnode)
        {
            if(currentnode->content == nextnode->content)
                return 1;
            nextnode = nextnode->next;
        }
        currentnode = currentnode->next;
    }
    return 0;
}
