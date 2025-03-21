/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:50 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/21 22:02:31 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **stack)
{
    *stack = ft_last_node_two(*stack);
    write(1, "rra\n", 4);
}
void    rrb(t_list **stack)
{
    *stack = ft_last_node_two(*stack);
    write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b)
{
    rra(stack_a);
    rrb(stack_b);
    write(1, "rrr\n", 4);
}
