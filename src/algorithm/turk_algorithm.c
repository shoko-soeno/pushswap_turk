/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 15:50:15 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 04:27:20 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	rr_to_target(t_node **a, t_node **b, t_node *chp, t_op_seq *op)
{
	while (*b != chp->target && *a != chp)
		rr(a, b, op, false);
}
/* current b node is not the cheapest a node's target, 
AND the current a node is not the top node */

static void rrr_to_target(t_node **a, t_node **b, t_node *chp, t_op_seq *op)
{
	while (*b != chp->target && *a != chp)
		rrr(a, b, op, false);
}
/* current b node is not the cheapest a node's target, 
AND the current a node is not the top node */

static void push_chp_from_a_to_b(t_node **a, t_node **b, t_op_seq *op)
{
	t_node	*chp;
	
	chp = find_cheapest_node(*a);
	if (chp->is_above_center && chp->target->is_above_center)
		rr_to_target(a, b, chp, op);
	else if (!(chp->is_above_center) && !(chp->target->is_above_center))
		rrr_to_target(a, b, chp, op);
    assign_indices(*a);
    assign_indices(*b);
	prep_for_push(a, chp, 'a', op);
	prep_for_push(b, chp->target, 'b', op);
	pb(b, a, op, false);
}

static void	push_chp_from_b_to_a(t_node **a, t_node **b, t_op_seq *op)
{
	prep_for_push(a, (*b)->target, 'a', op);
	pa(a, b, op, false);
}
//Ensure `b`'s target `a` node is on top of the stack

static void	min_on_top(t_node **a, t_op_seq *op)
{
	t_node *min_node = find_min_node(*a);
	
	while ((*a)->nbr != min_node->nbr)
	{
		if (min_node->is_above_center)
			ra(a, op, false);
		else
			rra(a, op, false);
	}
}

void	turk_sort(t_node **a, t_node **b, t_op_seq *op)
{
	int	size_a;

	size_a = ft_lstsize(*a);
	if (size_a-- > 3 && !is_sorted(*a)) //この関数を呼び出す前にis_sortedやsizeはチェック済みなので、この条件は不要かも？
		pb(b, a, op, false);
	if (size_a-- > 3 && !is_sorted(*a))
		pb(b, a, op, false);
	while (size_a-- > 3 && !is_sorted(*a))
	{
		setup_a(*a, *b);
		push_chp_from_a_to_b(a, b, op);
	}
	sort_three(a, op);
	while (*b)
	{
		setup_b(*a, *b);
		push_chp_from_b_to_a(a, b, op);
	}
	assign_indices(*a); //Refresh the current position of stack `a` これ不要かも？
	min_on_top(a, op); //Ensure smallest number is on top
}
