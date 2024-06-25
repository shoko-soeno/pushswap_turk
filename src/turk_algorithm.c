/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:50:15 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/25 19:00:45 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rr(a, b, false);
	current_index(*a);
	current_index(*b);
}
/* As long as the current `b` node is not `a` cheapest node's target node, 
and the current top `a` node is not the top node */

static void reverse_rotate_both(t_node **a, t_node **b, t_node *cheapest)
{
	while (*b != cheapest->target && *a != cheapest)
		rrr(a, b, false);
	current_index(*a);
	current_index(*b);
}
/* As long as the current `b` node is not `a` cheapest node's target node 
&& and the current `a` node is not the cheapest */

static void move_a_to_b(t_node **a, t_node *b)
{
	t_node	*cheapest;
	
	cheapest = get_cheapest(*a);
	if (cheapest->is_above_median && cheapest->target->is_above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->is_above_median) && !(cheapest->target->is_above_median))
		reverse_rotate_both(a, &b, cheapest);
	prep_for_push(a, cheapest, 'a');
	prep_for_push(b, cheapest->target, 'b');
	pb(b, a, false);
}

static void	move_b_to_a(t_node **a, t_node **b)
{
	prep_for_push(a, (*b)->target, 'a');
	pa(a, b, false);
}
//Define a function that prepares `b`'s target `a` nodes 
//for pushing all `b` nodes back to stack `a` 
//Ensure `b`'s target `a` node is on top of the stack

static void	min_on_top(t_node **a) //Define a function that moves the smallest number to the top
{
	while ((*a)->nbr != find_min(*a)->nbr) //As long as the smallest number is not at the top
	{
		if (find_min(*a)->is_above_median) //Rotate or reverse rotate according to the position of the node on the median
			ra(a, false);
		else
			rra(a, false);
	}
}
