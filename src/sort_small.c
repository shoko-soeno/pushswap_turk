/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/25 15:00:32 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//lst_atという関数を作成し、(*stack_a)->next->next->next->next->indexという書き方をしないで済むようにすべき
//sort_four, fiveは、最小値が上下どちらに近いかを判定してから、近い方に動かすと手数が減らせるはず。

void	sort_three(t_node **stack)
{
	t_node *max_node;
	
	max_node = find_max(*stack);
	if (max_node == *stack)
		ra(stack, false);
	else if (max_node == (*stack)->next)
		rra(stack, false);
	if ((*stack)->nbr > (*stack)->next->nbr)
		sa(stack, false);
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next->next->next->next->index == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while ((*stack_a)->index != 2)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small(t_list **stack_a, t_list **stack_b, size_t size)
{
	if (!*stack_a)
		return ;
	if (size == 1 || is_sorted(stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	return ;
}
