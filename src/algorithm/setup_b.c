/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 21:15:21 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 17:06:41 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

static void	find_target_for_b(t_node *a, t_node *b)
{
	t_node	*current_a;
	t_node	*target;
	long	best_match_value;

	while (b)
	{
		best_match_value = INT_MAX;
		current_a = a;
		while (current_a)
		{
			if (current_a->nbr > b->nbr && current_a->nbr < best_match_value)
			{
				best_match_value = current_a->nbr;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (best_match_value == INT_MAX)
			b->target = find_min_node(a);
		else
			b->target = target;
		b = b->next;
	}
}

void	setup_b(t_node *a, t_node *b)
{
	assign_indices(a);
	assign_indices(b);
	find_target_for_b(a, b);
}
