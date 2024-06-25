/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/23 15:15:43 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/25 15:24:39 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	reverse_rotate(t_node **stack)
{
	t_node	*head;
	t_node	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return (-1);
	head = *stack;
	last = ft_lstlast(head);
	while (head)
	{
		if (head->next->next == NULL) //最後から2番目の要素を見つける
		{
			head->next = NULL; //listの終わりを更新
			break ;
		}
		head = head->next;
	}
	last->next = *stack;//lastを先頭にする
	*stack = last;//listの先頭ポインタを更新
	return (0);
}

void	rra(t_node **stack_a, bool print)
{
	if (reverse_rotate(stack_a) == -1)
		return ;
	if(!print)
		ft_putendl_fd("rra", 1);
}

void	rrb(t_list **stack_b, bool print)
{
	if (reverse_rotate(stack_b) == -1)
		return ;
	if(!print)
		ft_putendl_fd("rrb", 1);
}

void	rrr(t_list **stack_a, t_list **stack_b, bool print)
{
	if ((ft_lstsize(*stack_a) < 2) || (ft_lstsize(*stack_b) < 2))
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	if(!print)
		ft_putendl_fd("rrr", 1);
}
