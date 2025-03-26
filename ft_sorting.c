/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:48:42 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/26 17:15:59 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_stack_size(t_list *stack)
{
	int		stack_size;
	t_list	*current;

	current = stack;
	while (stack != current->next)
	{
		stack_size++;
		current = current->next;
	}
	stack_size += 1;
	return (stack_size);
}

void	ft_sort(t_list **stack_a, t_list **stack_b, char **tmp,
		int split_control)
{
	int	size;

	size = lst_len(*stack_a);
	if (*stack_a)
	{
		if (size == 2)
			sa(stack_a);
		else if (size == 3)
			sort_three_args(stack_a);
		else
			to_many_args(stack_a, stack_b);
	}
	ft_free(*stack_a, tmp, split_control);
}
