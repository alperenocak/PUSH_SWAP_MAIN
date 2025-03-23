/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/21 15:37:44 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 17:25:19 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **stack, int write_flag)
{
	*stack = (*stack)->next;
	if (!write_flag)
		write(1, "ra\n", 3);
}

void	rb(t_list **stack, int write_flag)
{
	*stack = (*stack)->next;
	if (!write_flag)
		write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b, int write_flag)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (!write_flag)
		write(1, "rr\n", 3);
}
