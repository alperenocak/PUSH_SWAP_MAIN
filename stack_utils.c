/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 14:23:39 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/24 18:57:45 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*find_max(t_list *stack)
{
	t_list	*head;
	t_list	*max_node;
	long	max;

	max = INT_MIN;
	head = stack;
	while (stack)
	{
		if (stack->value > max)
		{
			max = stack->value;
			max_node = stack;
		}
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (max_node);
}

t_list	*find_min(t_list *stack)
{
	t_list	*head;
	t_list	*min_node;
	long	min;

	min = INT_MAX;
	head = stack;
	while (stack)
	{
		if (stack->value < min)
		{
			min = stack->value;
			min_node = stack;
		}
		stack = stack->next;
		if (stack == head)
			break ;
	}
	return (min_node);
}

void	if_arg_one(char **tmp, int split_control)
{
	int	i;

	i = 0;
	if (list_size(tmp) == 1)
	{
		if (ft_atol(tmp[i]) < INT_MIN || ft_atol(tmp[i]) > INT_MAX)
		{
			ft_free_and_error(NULL, tmp, split_control);
		}
		ft_free(NULL, tmp, split_control);
		exit(0);
	}
}
