/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:50:25 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/22 03:23:11 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    set_target_stack_b(t_list *stack_a, t_list *stack_b, int i, int j)
{
    t_list  *current_a;
    t_list  *target_node;
    int     best_match_index;
    
    current_a = stack_a;
    while(i-- != 0)
    {
        j = lst_len(stack_a);
        best_match_index = INT_MAX;
        while (j-- != 0)
        {
            if (current_a->value > stack_b->value 
                && current_a->value < best_match_index)
            {
                best_match_index = current_a->value;
				target_node = current_a;
            }
            current_a = current_a->next;
        }
        if (best_match_index == INT_MAX)
            stack_b->target_node = find_min(stack_a);
        else
            stack_b->target_node = target_node;
        stack_b = stack_b->next;
    }
}

void    initialize_stack_b(t_list *stack_a, t_list *stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    if (stack_b->next == NULL)
        set_target_stack_b(stack_a, stack_b, 1, lst_len(stack_a));
    else
        set_target_stack_b(stack_a, stack_b->next, lst_len(stack_b), lst_len(stack_a));
}