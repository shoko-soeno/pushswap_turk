/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 17:36:20 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 17:13:36 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_node	*find_min_node(t_node *stack)
{
	long	min;
	t_node	*min_node;

	if (stack == NULL)
		return (NULL);
	min_node = stack;
	while (stack)
	{
		if (stack->nbr < min_node->nbr)
		{
			min = stack->nbr;
			min_node = stack;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	*find_max_node(t_node *stack)
{
	long	max;
	t_node	*max_node;

	if (stack == NULL)
		return (NULL);
	max = stack->nbr;
	max_node = stack;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}

t_node	*find_cheapest_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->is_cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	prep_for_push(t_node **stack, t_node *node, char name, t_op_seq *op)
{
	while (*stack != node)
	{
		if (name == 'a')
		{
			if (node->is_above_center)
				ra(stack, op, false);
			else
				rra(stack, op, false);
		}
		else if (name == 'b')
		{
			if (node->is_above_center)
				rb(stack, op, false);
			else
				rrb(stack, op, false);
		}	
	}
}

void	min_on_top(t_node **a, t_op_seq *op)
{
	t_node	*min_node;

	min_node = find_min_node(*a);
	while ((*a)->nbr != min_node->nbr)
	{
		if (min_node->is_above_center)
			ra(a, op, false);
		else
			rra(a, op, false);
	}
}
