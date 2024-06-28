/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 07:43:34 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 19:48:25 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	push(t_node **stack_to, t_node **stack_from)
{
	t_node	*head_from;

	if (ft_lstsize(*stack_from) < 1)
		return (0);
	if (!*stack_from)
		return (0);
	head_from = *stack_from;
	*stack_from = head_from->next;
	if (!stack_to)
	{
		head_from->next = NULL;
	}
	else
	{
		head_from->next = *stack_to;
	}
	*stack_to = head_from;
	return (0);
}

void	pa(t_node **a, t_node **b, t_op_seq *op, bool print)
{
	if (push(a, b) == -1)
		return ;
	if (!print)
		op_seq_add(op, "pa");
}

void	pb(t_node **b, t_node **a, t_op_seq *op, bool print)
{
	if (push(b, a) == -1)
		return ;
	if (!print)
		op_seq_add(op, "pb");
}
