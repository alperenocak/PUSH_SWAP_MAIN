/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:46:48 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 17:47:22 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    ft_free(t_list *head, char **tmp, int split_control, int arg_size)
{
	int		i;
	t_list	*tmp_node;
	
	i = 0;
	if (split_control == 1)
	{
		while (tmp[i] != NULL)
		{
			free(tmp[i]);
			i++;
		}
		free(tmp);
	}
	i = 0;
	if (head)
	{
		while (i++ < arg_size)
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

void ft_free_and_error(t_list *head, char **tmp, int split_control, int arg_size)
{
	ft_free(head, tmp, split_control, arg_size);
	ft_error();
}