/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   same_or_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:41:51 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/24 23:49:44 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	lst_len(t_list *head)
{
	t_list	*tmp_head;
	int		i;

	i = 0;
	tmp_head = head;
	while (head->next != tmp_head)
	{
		head = head->next;
		i++;
	}
	return (i + 1);
}

int	ft_is_same_helper(t_list *start, t_list *current, int count)
{
	t_list	*temp;

	if (count == 0)
		return (1);
	temp = start;
	while (temp != current)
	{
		if (temp->value == current->value)
			return (0);
		temp = temp->next;
	}
	return (ft_is_same_helper(start, current->next, count - 1));
}

int	ft_is_same(t_list *head)
{
	int	size;

	if (!head)
		return (1);
	size = lst_len(head);
	if (size < 2)
		return (1);
	return (ft_is_same_helper(head, head->next, size - 1));
}

int	ft_is_sorted(t_list *head)
{
	t_list	*temp;

	temp = head;
	while (head)
	{
		if (head->value > head->next->value)
			return (1);
		head = head->next;
		if (head->next == temp)
			break ;
	}
	if (head->value < head->next->value)
		return (1);
	return (0);
}
