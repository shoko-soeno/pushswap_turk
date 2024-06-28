/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 19:59:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 02:06:06 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	assign_indices(t_node *stack)
{
	int	current_index;
	int	centor_index;

	current_index = 0;
	if (!stack)
		return ;
	centor_index = ft_lstsize(stack) / 2;
	while (stack)
	{
		stack->index = current_index;
		if (current_index <= centor_index)
			stack->is_above_center = true;
		else
			stack->is_above_center = false;
		stack = stack->next;
		++current_index;
	}
}

static void	find_target_for_a(t_node *a, t_node *b)
{
	t_node	*current_b;
	t_node  *target;
	int    best_match_value;

	while(a)
	{
		best_match_value = INT_MIN;
		target = NULL; //initialize
		current_b = b;
		while(current_b)
		{
			if (current_b->nbr < a->nbr
				&& current_b->nbr > best_match_value)
			{
				best_match_value = current_b->nbr;
				target = current_b;
			}
			current_b = current_b->next;
		}
		if (best_match_value == INT_MIN)
			a->target = find_max_node(b);
		else
			a->target = target;
		a = a->next;
	}
}

static void	calculate_cost(t_node *a, t_node *b)
{
	int size_a;
	int size_b;

	size_a = ft_lstsize(a);
	size_b = ft_lstsize(b);
	printf("inside calculate_cost size_a: %d\n", size_a); //debug
	printf("inside calculate_cost size_b: %d\n", size_b); //debug
	while (a)
	{
		if (a->is_above_center)
			a->cost = a->index;
		else if (!(a->is_above_center))
			a->cost = size_a - a->index;
		if (a->target->is_above_center)
			a->cost += a->target->index;
		else if (!(a->target->is_above_center))
			a->cost += size_b - a->target->index;
		a = a->next;
	}
}
/*
1. 最初にindexをデフォルトのコストとして設定
2. ノードaが中央より上にあるならcost = index、下にあるならreverse rotateを使うのでcost = size_a - index
3. bのtarget_nodeが中央より上にあるならcost += target_node->index、下にあるならcost += size_b - target_node->index
*/

void	set_cheapest_flag(t_node *stack)
{
	int		cheapest_cost;
	t_node	*cheapest_node;

	if(!stack)
		return;
	cheapest_cost = INT_MAX;
	while (stack)
	{
		if (stack->cost < cheapest_cost)
		{
			cheapest_cost = stack->cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->is_cheapest = true;
}

void	setup_a(t_node *a, t_node *b)
{
	assign_indices(a);
	assign_indices(b);
	find_target_for_a(a, b);
	calculate_cost(a, b);
	set_cheapest_flag(a);
}