/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:49:31 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 18:16:14 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_cheapest(t_list *stack)
{
    int     cheap;
    t_list  *cheap_node;
    t_list  *head;

    head = stack;
    if (!stack)
        return ;
    while (stack)
    {
        if (stack->cost < cheap)
        {
            cheap = stack->cost;
            cheap_node = stack;
        }
        stack = stack->next;
        if (head == stack)
            break;   
    }
    cheap_node->cheap = 1;
}

void    set_target_stack_a(t_list *stack_a, t_list *stack_b, int i, int j)
{
    t_list  *current_b;
    t_list  *target_node;
    int     best_match_index;
    
    while(i++ < ft_stack_size(stack_a))
    {
        j = 0;
        best_match_index = INT_MIN;
        while (j++ < ft_stack_size(stack_b))
        {
            if (current_b->value < stack_a->value 
                && current_b->value > best_match_index)
                {
                    best_match_index = current_b->value;
				target_node = current_b;
            }
            current_b = current_b->next;
        }
        if (best_match_index == INT_MIN)
            stack_a->target_node = find_max(stack_b);
        else
            stack_a->target_node = target_node;
        stack_a = stack_a->next;
    }
}

void    cost_calculation(t_list *stack_a, t_list *stack_b)
{
    int len_stack_a;
    int len_stack_b;
    t_list  *head;

    head = stack_a;
    len_stack_a = ft_stack_size(stack_a);
    len_stack_b = ft_stack_size(stack_b);
    while (stack_a)
    {
        stack_a->cost = stack_a->index;
        if (!(stack_a->median))
            stack_a->cost =len_stack_a - (stack_a->index);
        if (stack_a->target_node->median)
            stack_a->cost += stack_a->target_node->index;
        else
            stack_a->cost += len_stack_b - (stack_a->target_node->index);
        stack_a = stack_a -> next;
        if (stack_a == head)
            break;
    }
}
void    current_index(t_list *stack)
{
    int     i;
    int     median;
    t_list  *head;
    
    head = stack;
    i = 0;
    if (!stack)
        return ;
    median = ft_stack_size(stack) / 2;
    while(stack)
    {
        stack -> index = i;
        if (i <= median)
            stack->median = 1;
        else
            stack->median = 0;
        stack = stack->next;
        i++;
        if (stack == head)
            break;
    }
}

void    initialize_stack_a(t_list *stack_a, t_list *stack_b)
{
    int i;
    int j;
    i = 0;
    j = 0;
    current_index(stack_a);
    current_index(stack_b);
    set_target_stack_a(stack_a, stack_b, i);
    cost_calculation(stack_a, stack_b);
    find_cheapest(stack_a);
}