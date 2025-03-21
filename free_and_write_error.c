/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_and_write_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:46:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/21 21:48:06 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void    ft_free(t_list *head, char **tmp, int split_control)
{
	int		i;
	t_list	*tmp_node;
	int		arg_size;

	arg_size = list_size(tmp);
	i = 0;
	if (tmp)
	{
		if(split_control)
		{		
			while (i < arg_size)
				free(tmp[i++]);
			free(tmp);
		}
	}
	i = 0;
	if (head)
	{
		while (arg_size > i++)
		{
			tmp_node = head;
			head = head->next;
			free(tmp_node);
		}
	}
}

void    ft_error()
{
	write(1, "Error!", 6);
	exit(1);
}

void ft_free_and_error(t_list *head, char **tmp, int split_control)
{
	ft_free(head, tmp, split_control);
	ft_error();
}
