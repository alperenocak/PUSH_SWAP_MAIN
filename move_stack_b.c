/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:55:02 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 17:55:28 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    move_b_to_a(t_list **stack_a, t_list **stack_b)
{
    ready_for_push(stack_a, (*stack_b)->target_node, 'a');
    pa(stack_a, stack_b);
}