/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:49:31 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 01:28:16 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    find_cheapest(t_list *stack)
{
    int     cheap;
    t_list  *cheap_node;
    t_list  *head;

    if (!stack)
        return ;
    cheap = INT_MAX;
    cheap_node = NULL;
    head = stack;
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

void    set_target_stack_a(t_list *stack_a, t_list *stack_b, int a, int b)
{
    t_list  *current_b;
    t_list  *target_node;
    int     best_match_index;
    
    while(a-- != 0)
    {
        b = lst_len(stack_b);
        best_match_index = INT_MIN;
        current_b = stack_b;
        while (b-- != 0)
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
    len_stack_a = lst_len(stack_a);
    len_stack_b = lst_len(stack_b);
    while (stack_a)
    {
        stack_a->cost = stack_a->index;
        if (!(stack_a->median))
            stack_a->cost = len_stack_a - (stack_a->index);
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
    if (stack->next == NULL)
        return ;
    median = lst_len(stack) / 2;
    while(stack)
    {
        stack->index = i;
        if (stack->index <= median)
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
    current_index(stack_a);
    current_index(stack_b);
    set_target_stack_a(stack_a, stack_b, lst_len(stack_a), lst_len(stack_b));
    cost_calculation(stack_a, stack_b);
    find_cheapest(stack_a);
}