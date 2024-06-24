/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:35 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/23 15:13:32 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_list **stack)
{
	t_list	*head;
	t_list	*next;
	int		tmp_value;
	size_t	tmp_index;

	if (!stack || !*stack || !(*stack)->next)
		return (-1);
	head = *stack;
	next = head->next;
	tmp_value = head->value;
	tmp_index = head->index;
	head->value = next->value;
	head->index = next->index;
	next->value = tmp_value;
	next->index = tmp_index;
	return (0);
}

int	sa(t_list **stack_a)
{
	if (swap(stack_a) != 0)
		return (-1);
	ft_putendl_fd("sa", 1);
	return (0);
}

int	sb(t_list **stack_b)
{
	if (!swap(stack_b))
		return (false);
	ft_putendl_fd("sb", 1);
	return (true);
}

int	ss(t_list **stack_a, t_list **stack_b)
{
	if (!swap(stack_a) || !swap(stack_b))
		return (false);
	swap(stack_a);
	swap(stack_b);
	ft_putendl_fd("ss", 1);
	return (true);
}
