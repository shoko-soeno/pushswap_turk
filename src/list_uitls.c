/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_uitls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:07:31 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 23:48:18 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*ft_lstnew(int value)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->nbr = value;
	//new->index = 0;
	new->next = NULL;
	return (new);
}
// -1 means that the index is not set

void	ft_lstadd_front(t_node **stack, t_node *new)
{
	new->next = *stack; //nullチェック必要？
	*stack = new;
}

t_node	*ft_lstlast(t_node *stack)
{
	t_node	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_node **stack, t_node *new)
{
	t_node	*last;

	if(!stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		new->next = NULL; //循環リストなら不要？
	}
	else
	{
		last = ft_lstlast(*stack);
		last->next = new;
		new->next = NULL; //循環リストなら不要？
	}
}

size_t	ft_lstsize(t_node *head)
{
	size_t	i;
	t_node	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
