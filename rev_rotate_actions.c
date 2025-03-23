/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_actions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:58:50 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 02:47:25 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rra(t_list **stack, int write_flag)
{
    *stack = ft_last_node_two(*stack);
    if (!write_flag)
        write(1, "rra\n", 4);
}
void    rrb(t_list **stack, int write_flag)
{
    *stack = ft_last_node_two(*stack);
    if (!write_flag)
        write(1, "rrb\n", 4);
}

void    rrr(t_list **stack_a, t_list **stack_b, int write_flag)
{
    rra(stack_a, 1);
    rrb(stack_b, 1);
    if (!write_flag)
        write(1, "rrr\n", 4);
}
