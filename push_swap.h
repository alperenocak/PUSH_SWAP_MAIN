/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yuocak <yuocak@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 17:35:20 by yuocak            #+#    #+#             */
/*   Updated: 2025/03/26 17:46:19 by yuocak           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# define LONG_MAX 9223372036854775807
# define LONG_MIN (-9223372036854775807L - 1)

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				index;
	int				cost;
	int				median;
	int				cheap;
	struct s_list	*target_node;
	struct s_list	*next;
}					t_list;

t_list				*ft_create_list(char **tmp, int split_control);
t_list				*ft_last_node(t_list *head);
t_list				*ft_last_node_two(t_list *head);
t_list				*get_cheapest(t_list *stack);
t_list				*find_min(t_list *stack);
t_list				*find_max(t_list *stack);
int					lst_len(t_list *head);
int					list_size(char **tmp);
int					ft_stack_size(t_list *stack);
int					ft_is_same(t_list *head);
int					ft_is_sorted(t_list *head);
void				make_zero(t_list *stack);
void				if_arg_one(char **tmp, int split_control);

void				ft_error(void);
void				ft_free_and_error(t_list *head, char **tmp,
						int split_control);
void				ft_free(t_list *head, char **tmp, int split_control);

size_t				ft_strlcpy(char *dst, char *src, size_t dstsize);
void				*ft_memcpy(void *dst, void *src, size_t n);
char				**ft_split(char *s, char c);
long				ft_atol(char *av);

void				initialize_stack_a(t_list *stack_a, t_list *stack_b);
void				initialize_stack_b(t_list *stack_a, t_list *stack_b);
void				set_target_stack_b(t_list *stack_a, t_list *stack_b, int i,
						int j);
void				current_index(t_list *stack);

void				ft_sort(t_list **stack_a, t_list **stack_b, char **tmp,
						int split_control);
void				sort_three_args(t_list **stack_a);
void				to_many_args(t_list **stack_a, t_list **stack_b);
void				ft_control(char **av, int k, int f);
void				ft_exit_sorted(t_list *head, char **tmp, int split_control);
void				two_more_args(char *str);
int					digit_count_control(char *av);

void				move_a_to_b(t_list **stack_a, t_list **stack_b);
void				move_b_to_a(t_list **stack_a, t_list **stack_b);
void				ready_for_push(t_list **stack, t_list *top_node,
						char stack_name);
void				min_on_top(t_list **stack_a);

void				pa(t_list **stack_a, t_list **stack_b);
void				pb(t_list **stack_a, t_list **stack_b);

void				rra(t_list **stack, int write_flag);
void				rrb(t_list **stack, int write_flag);
void				rrr(t_list **stack_a, t_list **stack_b, int write_flag);

void				ra(t_list **stack, int write_flag);
void				rb(t_list **stack, int write_flag);
void				rr(t_list **stack_a, t_list **stack_b, int write_flag);

void				sa(t_list **stack);

#endif