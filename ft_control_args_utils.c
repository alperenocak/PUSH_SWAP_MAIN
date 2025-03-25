/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 15:30:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/25 15:35:23 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	two_more_args(char *str)
{
	while (*str)
	{
		if (*str == ' ')
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		str++;
	}
}

int	digit_count_control(char *av)
{
	int	digit_count;
	int	i;

	i = 0;
	while (av[i])
	{
		digit_count = 0;
		if (av[i] == '-' || av[i] == '+')
		{
			if (av[i] == '-' && av[i + 1] == '0' && (av[i + 2] == ' '
					|| av[i + 2] == '\0'))
				return (0);
			i++;
		}
		while (av[i] >= '0' && av[i] <= '9')
		{
			digit_count++;
			i++;
		}
		if (digit_count > 10)
			return (0);
		i++;
	}
	return (1);
}
