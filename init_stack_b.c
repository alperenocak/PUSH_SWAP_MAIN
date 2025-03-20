/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:50:25 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 17:52:32 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    initialize_stack_b(t_list *stack_a, t_list *stack_b)
{
    current_index(stack_a);
    current_index(stack_b);
    set_target_b(stack_a, stack_b);
}