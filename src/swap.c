/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:35 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 15:16:08 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_node **stack)
{
	t_node	*head;
	t_node	*next;
	int		tmp_nbr;
	size_t	tmp_index;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_nbr = head->nbr;
	tmp_index = head->index;
	head->nbr = next->nbr;
	head->index = next->index;
	next->nbr = tmp_nbr;
	next->index = tmp_index;
	return (0);
}

void	sa(t_node **stack_a, t_op_seq *op, bool print)
{
	if (swap(stack_a) != 0)
		return ;
	if(!print)
		op_seq_add(op, "sa");
}

void	sb(t_node **stack_b, t_op_seq *op, bool print)
{
	if (!swap(stack_b))
		return ;
	if(!print)
		op_seq_add(op, "sb");
}

void	ss(t_node **stack_a, t_node **stack_b, t_op_seq *op, bool print)
{
	if (!swap(stack_a) || !swap(stack_b))
		return ;
	swap(stack_a);
	swap(stack_b);
	if(!print)
		op_seq_add(op, "ss");
}
