/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_actions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:48:50 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/21 21:53:38 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list  *ft_last_node_two(t_list *head)
{
    t_list  *tmp_head;

    tmp_head = head;
    while (head)
    {
        if (head->next == tmp_head)
            return (head);
        head = head->next;
    }
}

void    swap(t_list **stack)
{
    t_list  *temp;
    t_list  *last_node;

    if ((*stack) == NULL || (*stack)->next == NULL)
        return ;
    last_node = ft_last_node_two(*stack);
    temp = *stack;
    if (ft_stack_size(*stack) == 2)
    {
        *stack = (*stack)->next;
        (*stack)->next = temp;
    }
    else 
    {
        last_node->next = (*stack)->next;
        *stack = (*stack)->next;
        temp->next = (*stack)->next;
        (*stack)->next = temp;
    }
}

void    sa(t_list **stack_a)
{
    swap(stack_a);
    write(1, "sa\n", 3);
}