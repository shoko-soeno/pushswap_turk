/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:34:45 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/28 15:02:55 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*node;

	if (!lst || !del)
		return ;
	while (*lst)
	{	
		node = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = node;
	}
}

// void del(void *content) {
// 	free(content);
// }
// int main() {
// 	t_list *head = malloc(sizeof(t_list));
// 	int *content = malloc(sizeof(int));
// 	*content = 42;
// 	head->content = content;
// 	head->next = NULL;
// 	ft_lstclear(&head, del);
// 	if (head == NULL) {
// 		printf("List is cleared.\n");
// 	}
// 	return 0;
// }