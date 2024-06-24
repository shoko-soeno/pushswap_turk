/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 19:49:50 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/23 15:30:09 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
//# include <stdio.h>
# include <limits.h>

// operations
int		swap(t_list **stack);
int		push(t_list **stack_to, t_list **stack_from);
int		rotate(t_list **stack);
int		reverse_rotate(t_list **stack);
int		sa(t_list **stack_a);
int		sb(t_list **stack_b);
int		ss(t_list **stack_a, t_list **stack_b);
int		pa(t_list **stack_a, t_list **stack_b);
int		pb(t_list **stack_b, t_list **stack_a);
int		ra(t_list **stack_a);
int		rb(t_list **stack_b);
int		rr(t_list **stack_a, t_list **stack_b);
int		rra(t_list **stack_a);
int		rrb(t_list **stack_b);
int		rrr(t_list **stack_a, t_list **stack_b);
// utils
void	ft_free(char **str);
int		is_sorted(t_list **stack);
void	make_top(t_list **stack, int distance);
void	free_stack(t_list **stack);
t_list	*ft_lstnew(int value);
void	sort_small(t_list **stack_a, t_list **stack_b, size_t size);
bool	ft_check_args(int argc, char **argv);
void	index_compression(t_list **stack);
void	radix_sort(t_list **stack_a, t_list **stack_b, size_t size);

#endif