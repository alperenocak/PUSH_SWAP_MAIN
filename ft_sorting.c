/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:48:42 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 17:51:32 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_stack_size(t_list *stack)
{
    int     stack_size;
    t_list  *current;
    
    current = stack;
    if (stack == NULL)
        return (0);
    
    while (stack != current -> next)
    {
        stack_size++;
        current = current -> next;
    }
    stack_size += 1;
    return (stack_size);
}

void    ft_sort(t_list **stack_a, t_list **stack_b)
{
    int size;

    size = ft_stack_size(*stack_a);
    if (!ft_is_sorted(stack_a))
    {
        if (size == 2)
            sa(stack_a);
        else if (size == 3)
            sort_three_args(stack_a);
        else if (size > 3)
            to_many_args(stack_a, stack_b);
    }
    free_stack(stack_a, stack_b);
}