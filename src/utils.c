/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 22:37:50 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 23:10:10 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i])
		i++;
	while (i > 0)
	{
		free(str[--i]);
	}
	free(str);
}

bool	is_sorted(t_node *stack)
{
	if (stack == NULL)
		return (false);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	free_stack(t_node **stack) //ダブルポインタから普通のポインタにしてしまえば、関数内での変更が外にも反映される
{
	t_node	*head;
	t_node	*tmp;

	if (!stack || !*stack)
		free(stack);　//ここが漏れていたせいでリークした！
		return ;
	head = *stack;
	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
	free(stack);
}

void	print_node(t_node *head)
{
	t_node	*tmp;

	tmp = head;
	while (tmp != NULL)
	{
		ft_putnbr_fd(tmp->nbr, 1);
		ft_putendl_fd("", 1);
		tmp = tmp->next;
	}
}
