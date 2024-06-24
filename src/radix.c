/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:28 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/23 23:06:43 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	get_max_bits(t_list **stack)
{
	t_list	*head;
	size_t	max;
	size_t	max_bits;
	size_t	index;

	head = *stack;
	if (!head)
		return (0);
	max = head->index;
	max_bits = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
//indexはすでに座標圧縮されているので、この最大値-1のbit_widthがmax_bitsになる。
//例えば、最大値が10なら、10は1010なので、bit_widthは4になる。
//今のget_max_bitsはより効率化できるはず。

void	radix_sort(t_list **stack_a, t_list **stack_b, size_t size)
{
	t_list	*head_a;
	size_t	i;
	size_t	j;
	size_t	max_bits;

	i = 0;
	head_a = *stack_a;
	max_bits = get_max_bits(stack_a);
	while (i < max_bits)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = *stack_a;
			if (!head_a)
				break ;
			if (((head_a->index >> i) & 1) == 1)
				ra(stack_a);
			else
				pb(stack_a, stack_b);
		}
		while (ft_lstsize(*stack_b) != 0)
			pa(stack_a, stack_b);
		i++;
	}
}
