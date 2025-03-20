/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:35:20 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/20 18:19:39 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
    int value;
    int index;
    int cost;
    int median;
    int cheap;
    struct s_list   *target_node;
    struct s_list   *next;
}t_list;

t_list  *ft_create_list(char **tmp, int split_control);
size_t	ft_strlcpy(char *dst, char *src, size_t dstsize);
void    initialize_stack_a(t_list *stack_a, t_list *stack_b);
void    current_index(t_list *stack);
void    ft_error();
void    ft_free_and_error(t_list *head, char **tmp, int split_control, int arg_size);
void    ft_free(t_list *head, char **tmp, int split_control, int arg_size);
void	*ft_memcpy(void *dst, void *src, size_t n);
char	**ft_split(char *s, char c);
int	    ft_is_same(t_list *head);
int     ft_is_sorted(t_list *head);
long    ft_atol(char *av);
int     ft_stack_size(t_list *stack);
void    ft_sort(t_list **stack_a, t_list **stack_b);
void    sort_three_args(t_list **stack_a);
void    to_many_args(t_list **stack_a, t_list **stack_b);
void    ft_control(char **av);
void    move_a_to_b(t_list **stack_a, t_list **stack_b);
void    initialize_stack_b(t_list *stack_a, t_list *stack_b);
void    ready_for_push(t_list **stack, t_list *top_node, char stack_name);
t_list  *get_cheapest(t_list *stack);

# endif