/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:49:50 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 17:23:38 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int				cost;
	bool			is_cheapest;
	bool			is_above_center;
	struct s_node	*next;
	struct s_node	*target;
}	t_node;

typedef struct s_op_seq
{
	char	*arr[40000];
	int		size;
}				t_op_seq;

//stock actions
t_op_seq	*op_seq_init(void);
void		op_seq_free(t_op_seq *op);
void		op_seq_add(t_op_seq *op, char *op_str);
// stack utils
t_node		*ft_lstnew(int value);
void		ft_lstadd_back(t_node **stack, t_node *new);
size_t		ft_lstsize(t_node *head);
t_node		*ft_lstlast(t_node *stack);
t_node		*find_min_node(t_node *stack);
t_node		*find_max_node(t_node *stack);
// stack initiation
void		setup_a(t_node *a, t_node *b);
void		setup_b(t_node *a, t_node *b);
void		assign_indices(t_node *stack);
void		set_cheapest_flag(t_node *stack);
t_node		*find_cheapest_node(t_node *stack);
//Prep the required nodes on top for pushing
void		prep_for_push(t_node **stack, t_node *node, char c, t_op_seq *op);
// other utils
long		ft_atol(const char *str);
bool		is_sorted(t_node *stack);
void		ft_free(char **str);
void		free_stack(t_node **stack);
bool		ft_check_args(int argc, char **argv);
void		min_on_top(t_node **a, t_op_seq *op);
// operations
//swap
void		sa(t_node **a, t_op_seq *op, bool print);
void		sb(t_node **b, t_op_seq *op, bool print);
void		ss(t_node **a, t_node **b, t_op_seq *op, bool print);
//rotate
void		ra(t_node **a, t_op_seq *op, bool print);
void		rb(t_node **b, t_op_seq *op, bool print);
void		rr(t_node **a, t_node **b, t_op_seq *op, bool print);
//reverse rotate
void		rra(t_node **a, t_op_seq *op, bool print);
void		rrb(t_node **b, t_op_seq *op, bool print);
void		rrr(t_node **a, t_node **b, t_op_seq *op, bool print);
//push
void		pa(t_node **a, t_node **b, t_op_seq *op, bool print);
void		pb(t_node **b, t_node **a, t_op_seq *op, bool print);
//Algorithm
void		sort_small(t_node **stack_a, int size, t_op_seq *op);
void		sort_three(t_node **stack, t_op_seq *op);
void		turk_sort(t_node **a, t_node **b, t_op_seq *op);
//debug
// void		print_node(t_node *head);

#endif