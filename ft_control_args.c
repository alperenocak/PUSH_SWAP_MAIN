/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:35:49 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 23:33:12 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	ft_control_args(char *av)
{
	int	i;

	i = 0;
	if ((av[0] > '9' || av[0] < '0') && (av[0] != '+' && av[0] != '-'))
		return (0);
	if (!digit_count_control(av))
		return (0);
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') && !(av[i + 1] == '-'
				|| av[i + 1] == '+'))
			i++;
		else if ((av[i] == '-' || av[i] == '+') && !(av[i + 1] == '-' || av[i
					+ 1] == '+') && (av[i + 1] >= '0' && av[i + 1] <= '9'))
			i++;
		else if (av[i] == ' ' && (av[i + 1] <= '9' && av[i + 1] >= '0'))
			i++;
		else if (av[i] == ' ' && (av[i + 1] == '+' || av[i + 1] == '-'))
			i++;
		else
			return (0);
	}
	return (1);
}

void	ft_control(char **av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!ft_control_args(av[i]))
		{
			write(2, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
