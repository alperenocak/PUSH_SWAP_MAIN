/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:07:45 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/22 03:22:25 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    push_a(t_list **stack_a, t_list **stack_b, t_list *temp)
{
    if((*stack_b)->next == NULL)
    {
        ft_last_node_two(*stack_a)->next = *stack_b;
        (*stack_b)->next = *stack_a;
        *stack_a = *stack_b;
        *stack_b = NULL;
        return ;
    }
    if (lst_len(*stack_b) == 2)
    {
        temp = *stack_b;
        (*stack_b)->next->next = NULL;
        *stack_b = (*stack_b)->next;
        ft_last_node_two(*stack_a)->next = temp;
        temp->next = *stack_a;
        *stack_a = temp;
        return ;
    }
    temp = *stack_b;
    ft_last_node_two(*stack_b)->next = (*stack_b)->next;
    *stack_b = (*stack_b)->next;
    ft_last_node_two(*stack_a)->next = temp;
    temp->next = *stack_a;
    *stack_a = temp;
}

void   push_b(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;
    
    if ((*stack_b) == NULL)
    {
        temp = ft_last_node_two(*stack_a);
        *stack_b = *stack_a;
        *stack_a = (*stack_a)->next;
        temp->next = *stack_a;
        (*stack_b)->next = NULL;
        return ;
    }
    temp = *stack_a;
    ft_last_node_two(*stack_a)->next = (*stack_a)->next;
    *stack_a = (*stack_a)->next;
    if ((*stack_b)->next == NULL)
    {
        (*stack_b)->next = temp;
        temp->next = *stack_b;
        *stack_b = temp;
        return ;
    }
    ft_last_node_two(*stack_b)->next = temp;
    temp->next = (*stack_b);
    (*stack_b) = temp;
}

void    pa(t_list **stack_a, t_list **stack_b)
{
    t_list  *temp;

    push_a(stack_a, stack_b, temp);
    write(1, "pa\n", 3);
}

void    pb(t_list **stack_a, t_list **stack_b)
{
    push_b(stack_a, stack_b);
    write(1, "pb\n", 3);
}