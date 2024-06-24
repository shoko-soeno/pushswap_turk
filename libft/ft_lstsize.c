/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:36:09 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/22 17:13:23 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current_node;

	count = 0;
	current_node = lst;
	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}

// int main() {
// 	t_list *head = NULL;
// 	printf("Test Empty List: Expected 0, Got %d\n", ft_lstsize(head));
// 	// Add one node
// 	head = ft_lstnew("Hello, World!");
// 	printf("Test Single Node List: Expected 1, Got %d\n", ft_lstsize(head));
// 	// Add more nodes
// 	head->next = ft_lstnew("Node 2");
// 	head->next->next = ft_lstnew("Node 3");
// 	printf("Test Three Nodes List: Expected 3, Got %d\n", ft_lstsize(head));
// 	// Free memory
// 	t_list *current = head;
// 	while (current != NULL) {
// 		t_list *temp = current;
// 		current = current->next;
// 		free(temp);
// 	}
// 	return 0;
// }