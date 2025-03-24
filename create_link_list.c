/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_link_list.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:38:35 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/24 04:15:54 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	list_size(char **tmp)
{
	int	lst_len;

	lst_len = 0;
	while (tmp[lst_len])
		lst_len++;
	return (lst_len);
}

t_list	*ft_last_node(t_list *head)
{
	while (head->next)
		head = head->next;
	return (head);
}

t_list	*ft_new_node(long number)
{
	t_list	*new_node;

	if (number < INT_MIN || number > INT_MAX)
		return (NULL);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return (0);
	new_node->value = number;
	new_node->next = NULL;
	return (new_node);
}

void	add_to_list(t_list **head, t_list *node)
{
	t_list	*tmp_node;

	if (!(*head))
		*head = node;
	else
	{
		tmp_node = ft_last_node(*head);
		tmp_node->next = node;
	}
}

t_list	*ft_create_list(char **tmp, int split_control)
{
	t_list	*node;
	t_list	*head;
	int		i;

	node = NULL;
	head = NULL;
	i = 0;
	if_arg_one(tmp, split_control);
	while (tmp[i] != NULL)
	{
		node = ft_new_node(ft_atol(tmp[i]));
		if (!node)
			ft_free_and_error(head, tmp, split_control);
		add_to_list(&head, node);
		i++;
	}
	node->next = head;
	if (!ft_is_same(head))
		ft_free_and_error(head, tmp, split_control);
	if (!ft_is_sorted(head))
		return (ft_free(head, tmp, split_control), exit(1), NULL);
	make_zero(head);
	return (head);
}
