/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:37:44 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/21 17:09:01 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void    ra(t_list **stack)
{
    *stack = (*stack)->next;
    write(1, "ra\n", 3);
}
void    rb(t_list **stack)
{
    *stack = (*stack)->next;
    write(1, "ra\n", 3);
}

void    rr(t_list **stack_a, t_list **stack_b)
{
    ra(stack_a);
    rb(stack_b);
    write(1, "rr\n", 3);
}