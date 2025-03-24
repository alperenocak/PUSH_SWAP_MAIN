/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_write_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:46:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/25 00:11:03 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_free(t_list *head, char **tmp, int split_control)
{
	int		i;
	t_list	*current;
	t_list	*next_node;

	i = 0;
	if (tmp && split_control)
	{
		while (tmp[i])
			free(tmp[i++]);
		free(tmp);
	}
	if (head)
	{
		current = head;
		next_node = current->next;
		free(current);
		current = next_node;
		while (current != NULL && current != head)
		{
			next_node = current->next;
			free(current);
			current = next_node;
		}
	}
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit(0);
}

void	ft_free_and_error(t_list *head, char **tmp, int split_control)
{
	ft_free(head, tmp, split_control);
	ft_error();
}

void	ft_exit_sorted(t_list *head, char **tmp, int split_control)
{
	ft_free(head, tmp, split_control);
	exit(0);
}
