/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:35 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/25 15:49:30 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	rotate(t_node **stack)
{
	t_node	*head;
	t_node	*last;

	if (ft_lstsize(*stack) < 2)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	*stack = head->next;
	head->next = NULL;
	last->next = head;
	return (0);
}

void	ra(t_node **stack_a, bool print)
{
	if (rotate(stack_a) == -1)
		return (-1);
	if (!print)
		ft_putendl_fd("ra", 1);
	return (0);
}

void	rb(t_node **stack_b, bool print)
{
	if (rotate(stack_b) == -1)
		return (-1);
	if(!print)
		ft_putendl_fd("rb", 1);
	return (0);
}

void	rr(t_node **stack_a, t_node **stack_b, bool print)
{
	rotate(stack_a);
	rotate(stack_b);
	if(!print)
		ft_putendl_fd("rr", 1);
}
