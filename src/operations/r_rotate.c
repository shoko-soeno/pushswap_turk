/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:15:43 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 16:39:56 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static int	r_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL)
		{
			head->next = NULL;
			break ;
		}
		head = head->next;
	}
	last->next = *stack;
	*stack = last;
	return (0);
}

void	rra(t_node **stack_a, t_op_seq *op, bool print)
{
	if (r_rotate(stack_a) == -1)
		return ;
	if (!print)
		op_seq_add(op, "rra");
}

void	rrb(t_node **stack_b, t_op_seq *op, bool print)
{
	if (r_rotate(stack_b) == -1)
		return ;
	if (!print)
		op_seq_add(op, "rrb");
}

void	rrr(t_node **stack_a, t_node **stack_b, t_op_seq *op, bool print)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	r_rotate(stack_a);
	r_rotate(stack_b);
	if (!print)
		op_seq_add(op, "rrr");
}
