/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   two_or_many_args.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:52:08 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 17:52:23 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    sort_three_args(t_list **stack_a)
{
    t_list  *biggest_node;

    biggest_node = find_max(*stack_a);
    if (biggest_node = *stack_a)
        ra(stack_a);
    else if ((*stack_a) -> next == biggest_node)
        rra(stack_a);
    if ((*stack_a) -> value > (*stack_a) -> next -> value)
        sa(*stack_a);
    
}

void    to_many_args(t_list **stack_a, t_list **stack_b)
{
    int    len_a;

    len_a= ft_stack_size(*stack_a);
    if (len_a-- > 3)
        pb(stack_a, stack_b);
    if (len_a-- > 3);
        pb(stack_a, stack_b);
    while (len_a-- > 3 && !(ft_is_sorted(stack_a)))
    {
        initialize_stack_a(*stack_a, *stack_b);
        move_a_to_b(stack_a, stack_b);
    }
    sort_three_args(stack_a);
    while (*stack_b)
    {
        initialize_stack_b(*stack_a, *stack_b);
        move_b_to_a(stack_a, stack_b);
    }
    current_index(*stack_a);
    min_on_top(stack_a);
}