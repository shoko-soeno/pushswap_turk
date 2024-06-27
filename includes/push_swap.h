/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:49:50 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/27 20:46:15 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				index;
	int 			cost;
	bool			cheapest;
	bool			is_above_median;
	struct s_node	*next;
	//struct s_node	*prev; //不要？？
	struct s_node	*target;
}	t_node;

typedef struct s_op_seq
{
	char	*arr[40000];
	int		size;
}				t_op_seq;

//stock actions
t_op_seq	*op_seq_init();
void		op_seq_free(t_op_seq *op);
void		op_seq_push(t_op_seq *op, char *op_str);

// stack utils
t_node	*ft_lstnew(int value);
//***Stack utils
int		stack_len(t_node *stack); //Calculate the length of a stack
t_node	*find_last(t_node *stack); //Find the last node of a stack
bool	stack_sorted(t_node *stack); //To check whether a stack is sorted
t_node	*find_min(t_node *stack); //Find the smallest number
t_node	*find_max(t_node *stack); //Find the biggest number

// stack initiation
void	init_stack_a(t_node **a, char **argv); //Initiate stack `a` before processing

// node initiation
void	init_nodes_a(t_node *a, t_node *b); //To prep all nodes for pushing `a` to `b`
void	init_nodes_b(t_node *a, t_node *b); //To prep all nodes for pushing `b` back to `a`
void	current_index(t_node *stack); //Set the node's current index
void	set_cheapest(t_node *stack); //Set the stack's cheapest node
t_node	*get_cheapest(t_node *stack); //Get the cheapest node of a stack
void	prep_for_push(t_node **s, t_node *n, char c); //Prep the required nodes on top for pushing

// other utils
int		is_sorted(t_node **stack);
void	ft_free(char **str);
void	free_stack(t_node **stack);
bool	ft_check_args(int argc, char **argv);
void	index_compression(t_node **stack);

// operations
// int		swap(t_node **stack);
// int		push(t_node **stack_to, t_node **stack_from);
// int		rotate(t_node **stack);
// int		reverse_rotate(t_node **stack);
// int		sa(t_node **stack_a);
// int		sb(t_node **stack_b);
// int		ss(t_node **stack_a, t_node **stack_b);
// int		pa(t_node **stack_a, t_node **stack_b);
// int		pb(t_node **stack_b, t_node **stack_a);
// int		ra(t_node **stack_a);
// int		rb(t_node **stack_b);
// int		rr(t_node **stack_a, t_node **stack_b);
// int		rra(t_node **stack_a);
// int		rrb(t_node **stack_b);
// int		rrr(t_node **stack_a, t_node **stack_b);
void	sa(t_node **a, bool print);
void	sb(t_node **b, bool print);
void	ss(t_node **a, t_node **b, bool print);
void	ra(t_node **a, bool print);
void	rb(t_node **b, bool print);
void	rr(t_node **a, t_node **b, bool print);
void	rra(t_node **a, bool print);
void	rrb(t_node **b, bool print);
void	rrr(t_node **a, t_node **b, bool print);
void	pa(t_node **a, t_node **b, bool print);
void	pb(t_node **b, t_node **a, bool print);

//Algorithm
void	sort_three(t_node **a);
void	sort_small(t_node **stack_a, t_node **stack_b, size_t size);
void	sort_stacks(t_node **a, t_node **b);

#endif