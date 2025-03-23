/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:34:23 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 16:47:18 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	else if ((ac == 2) && !(av[1][0] == '\0'))
	{
		ft_control(av + 1);
		av = ft_split(av[1], ' ');
		stack_a = ft_create_list(av, 1);
		ft_sort(&stack_a, &stack_b, av, 1);
	}
	else if (ac > 2)
	{
		ft_control(av + 1);
		stack_a = ft_create_list(av + 1, 0);
		ft_sort(&stack_a, &stack_b, av + 1, 0);
	}
	return (0);
}
