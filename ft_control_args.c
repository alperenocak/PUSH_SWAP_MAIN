/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:35:49 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/23 19:08:42 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_control_args(char *av)
{
	int	i;

	i = 0;
	if ((av[0] > '9' || av[0] < '0') && (av[0] != '+' && av[0] != '-'))
		return (0);
	else if (av[i] == '-' && (av[i + 1] == '0'))
		return (0);
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9') && !(av[i + 1] == '-'
				|| av[i + 1] == '+'))
			i++;
		else if ((av[i] == '-' || av[i] == '+') && !(av[i + 1] == '-'
				|| av[i + 1] == '+') && (av[i + 1] >= '0' && av[i + 1] <= '9'))
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
			write(1, "Error\n", 6);
			exit(1);
		}
		i++;
	}
}
