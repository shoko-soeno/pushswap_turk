/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:41 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/23 23:37:41 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//lstaddという関数を作成し、(*stack_a)->next->next->next->next->indexという書き方をしないで済むようにすべき
//sort_four, fiveは、最小値が上下どちらに近いかを判定してから、近い方に動かすと手数が減らせるはず。

static void	sort_three(t_list **stack_a)
{
	size_t	first;
	size_t	second;
	size_t	third;

	if (!*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		sa(stack_a);
	else if (first > second && second > third && first > third)
	{
		sa(stack_a);
		rra(stack_a);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a);
		ra(stack_a);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a);
}

static void	sort_four(t_list **stack_a, t_list **stack_b)
{
	while ((*stack_a)->index != 1)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
}

static void	sort_five(t_list **stack_a, t_list **stack_b)
{
	if ((*stack_a)->next->next->next->next->index == 1)
	{
		rra(stack_a);
		pb(stack_a, stack_b);
	}
	else
	{
		while ((*stack_a)->index != 1)
			ra(stack_a);
		pb(stack_a, stack_b);
	}
	while ((*stack_a)->index != 2)
		ra(stack_a);
	pb(stack_a, stack_b);
	sort_three(stack_a);
	pa(stack_a, stack_b);
	pa(stack_a, stack_b);
}

void	sort_small(t_list **stack_a, t_list **stack_b, size_t size)
{
	if (!*stack_a)
		return ;
	if (size == 1 || is_sorted(stack_a))
		return ;
	if (size == 2)
		sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_four(stack_a, stack_b);
	else if (size == 5)
		sort_five(stack_a, stack_b);
	return ;
}
