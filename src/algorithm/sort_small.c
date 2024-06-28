/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 04:26:58 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

//lst_atという関数を作成し、(*stack_a)->next->next->next->next->indexという書き方をしないで済むようにすべき
//sort_four, fiveは、最小値が上下どちらに近いかを判定してから、近い方に動かすと手数が減らせるはず。

void	sort_three(t_node **stack, t_op_seq *op)
{
	t_node *max_node;
	
	max_node = find_max_node(*stack);
	if (max_node == *stack)
		ra(stack, op, false);
	else if (max_node == (*stack)->next)
		rra(stack, op, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, op, false);
}

void	sort_small(t_node **stack_a, int size, t_op_seq *op)
{
	if (!*stack_a)
		return ;
	if (size == 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a, op, false);
	else if (size == 3)
		sort_three(stack_a, op);
	// else if (size == 4)
	// 	sort_four(stack_a, stack_b, op);
	// else if (size == 5)
	// 	sort_five(stack_a, stack_b, op);
	return ;
}
