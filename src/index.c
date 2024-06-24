/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:42:53 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/23 18:55:36 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*get_next_min(t_list **stack)
{
	t_list	*head;
	t_list	*min;

	min = NULL;
	head = *stack;
	while (head)
	{
		if (!head->initialized && (!min || head->value < min->value))
			min = head;
		head = head->next;
	}
	return (min);
}

void	index_compression(t_list **stack)
{
	t_list	*head;
	int		index;

	index = 1;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head->initialized = true;
		head = get_next_min(stack);
	}
}
