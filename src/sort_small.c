/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 15:06:31 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//lst_atという関数を作成し、(*stack_a)->next->next->next->next->indexという書き方をしないで済むようにすべき
//sort_four, fiveは、最小値が上下どちらに近いかを判定してから、近い方に動かすと手数が減らせるはず。

void	sort_three(t_node **stack, t_op_seq *op)
{
	t_node *max_node;
	
	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack, op, false);
	else if (max_node == (*stack)->next)
		rra(stack, op, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, op, false);
}

static void	sort_four(t_node **stack_a, t_node **stack_b, t_op_seq *op)
{
	while ((*stack_a)->index != 1)
		ra(stack_a, op, 1);
	pb(stack_a, stack_b, op, 1);
	sort_three(stack_a, op);
	pa(stack_a, stack_b, op, 1);
}

static void	sort_five(t_node **stack_a, t_node **stack_b, t_op_seq *op)
{
	if ((*stack_a)->next->next->next->next->index == 1)
	{
		rra(stack_a, op, 1);
		pb(stack_a, stack_b, op, 1);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ra(stack_a, op, 1);
		pb(stack_a, stack_b, op, 1);
	}
	while ((*stack_a)->index != 2)
		ra(stack_a, op, 1);
	pb(stack_a, stack_b, op, 1);
	sort_three(stack_a, op);
	pa(stack_a, stack_b, op, 1);
	pa(stack_a, stack_b, op, 1);
}

void	sort_small(t_node **stack_a, t_node **stack_b, int size, t_op_seq *op)
{
	if (!*stack_a)
		return ;
	if (size == 1 || is_sorted(*stack_a))
		return ;
	if (size == 2)
		sa(stack_a, op, 1);
	else if (size == 3)
		sort_three(stack_a, op);
	else if (size == 4)
		sort_four(stack_a, stack_b, op);
	else if (size == 5)
		sort_five(stack_a, stack_b, op);
	return ;
}
