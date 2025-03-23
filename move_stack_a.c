/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:54:36 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 02:48:08 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
    while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
        rr(stack_a, stack_b, 0);
    current_index(*stack_a);
    current_index(*stack_b);
}    

void    rev_rotate_both(t_list **stack_a, t_list **stack_b, t_list *cheapest_node)
{
    while (*stack_b != cheapest_node->target_node && *stack_a != cheapest_node)
        rrr(stack_a, stack_b, 0);
    current_index(*stack_a);
    current_index(*stack_b);
}

void    ready_for_push(t_list **stack, t_list *top_node, char stack_name)
{
    while (*stack != top_node)
    {
        if (stack_name == 'a')
        {
            if(top_node->median)
                ra(stack, 0);
            else
                rra(stack, 0);
        }
        else if (stack_name == 'b')
        {
            if(top_node->median)
                rb(stack, 0);
            else
                rrb(stack, 0);
        }   
    }
}

t_list  *get_cheapest(t_list *stack)
{
    t_list  *head;

    head = stack;
    if (!stack)
        return (NULL);
    while(stack)
    {
        if(stack->cheap)
            return (stack);
        stack = stack->next;
    }
    return (NULL);
}
void    move_a_to_b(t_list **stack_a, t_list **stack_b)
{
    t_list  *cheapest_node;
    
    cheapest_node = get_cheapest(*stack_a);
    if (cheapest_node->median 
        && cheapest_node->target_node->median)
        rotate_both(stack_a, stack_b, cheapest_node);
    else if (!(cheapest_node->median) 
        && !(cheapest_node->target_node->median))
        rev_rotate_both(stack_a, stack_b, cheapest_node);
    ready_for_push(stack_a, cheapest_node, 'a');
    ready_for_push(stack_b, cheapest_node->target_node, 'b');
    pb(stack_a, stack_b);
}