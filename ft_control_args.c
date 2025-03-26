/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:35:49 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/26 17:47:51 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	return (c == ' ');
}

static int	ft_is_valid_sign(char *str, int *i)
{
	if (str[*i] == '-')
	{
		if (str[*i + 1] == '0'
			&& (str[*i + 2] == ' ' || str[*i + 2] == '\0'))
			return (0);
		(*i)++;
	}
	else if (str[*i] == '+')
		(*i)++;
	return (1);
}

static int	ft_check_digits(char *str, int *i)
{
	int	digit_count;

	digit_count = 0;
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		digit_count++;
		(*i)++;
	}
	return (digit_count <= 10);
}

int	ft_control_args(char *av, int f)
{
	int	i;

	i = 0;
	while (ft_isspace(av[i++]) == '\0' && f == 1)
		write (2, "Error\n", 6);
	while (ft_isspace(av[i]))
		i++;
	if (av[i] == '\0' || ((av[i] > '9' || av[i] < '0')
			&& (av[i] != '+' && av[i] != '-')))
		return (0);
	while (av[i])
	{
		while (ft_isspace(av[i]))
			i++;
		if ((av[i] == '-' || av[i] == '+') && (av[i + 1] <= '0'
				|| av[i + 1] >= '9'))
			return (0);
		if (!ft_is_valid_sign(av, &i))
			return (0);
		if (!ft_check_digits(av, &i))
			return (0);
		if (av[i] != ' ' && av[i] != '\0')
			return (0);
	}
	return (1);
}

void	ft_control(char **av, int k, int f)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (k == 0)
			two_more_args(av[i]);
		i++;
	}
	i = 0;
	while (av[i])
	{
		if (!ft_control_args(av[i], f))
		{
			write(2, "Error\n", 6);
			exit(0);
		}
		i++;
	}
}
