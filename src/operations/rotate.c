/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:35 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 16:40:56 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*last;

	if (!stack || !*stack)
		return (-1);
	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}

void	ra(t_node **stack_a, t_op_seq *op, bool print)
{
	if (rotate(stack_a) == -1)
		return ;
	if (!print)
		op_seq_add(op, "ra");
}

void	rb(t_node **stack_b, t_op_seq *op, bool print)
{
	if (rotate(stack_b) == -1)
		return ;
	if (!print)
		op_seq_add(op, "rb");
}

void	rr(t_node **stack_a, t_node **stack_b, t_op_seq *op, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if (!print)
		op_seq_add(op, "rr");
}
