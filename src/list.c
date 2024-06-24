/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 00:07:31 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/24 12:22:53 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstnew(int value)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(*new));
	if (!new)
		return (NULL);
	new->value = value;
	new->index = 0;
	new->initialized = false;
	new->next = NULL;
	return (new);
}
// -1 means that the index is not set

void	ft_lstadd_front(t_list **stack, t_list *new)
{
	new->next = *stack; //nullチェック必要では？
	*stack = new;
}

t_list	*ft_lstlast(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	if (!tmp)
		return (NULL);
	while (tmp->next)
	{
		tmp = tmp->next;
	}
	return (tmp);
}

void	ft_lstadd_back(t_list **stack, t_list *new)
{
	t_list	*last;

	if (!*stack)
	{
		*stack = new;
		new->next = NULL;
	}
	else
	{
		last = ft_lstlast(*stack);
		last->next = new;
		new->next = NULL;
	}
}

size_t	ft_lstsize(t_list *head)
{
	size_t	i;
	t_list	*tmp;

	tmp = head;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
