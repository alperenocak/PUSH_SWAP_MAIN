/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_zero.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/22 00:55:23 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/22 01:00:07 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    make_zero(t_list *stack)
{
    t_list  *head;

    head = stack;
    while (stack)
    {   
        stack->cheap = 0;
        stack->cost = 0;
        stack->index = 0;
        stack->median = 0;
        stack->target_node = NULL;
        stack = stack->next;
        if (stack == head)
            break ;
    }
}