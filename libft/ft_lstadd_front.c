/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:34:38 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/23 23:23:34 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// void print_list(t_list *lst) {
// 	while (lst != NULL) {
// 		printf("%d -> ", *(int *)lst->content);
// 		lst = lst->next;
// 	}
// 	printf("NULL\n");
// }
// int main() {
// 	t_list *head = NULL;
// 	int *p1 = malloc(sizeof(int));
// 	int *p2 = malloc(sizeof(int));
// 	int *p3 = malloc(sizeof(int));
// 	if(p1 == NULL || p2 == NULL || p3 == NULL){
// 		return -1;
// 	}
// 	*p1 = 42;
// 	*p2 = 43;
// 	*p3 = 44;
// 	//make a new node and at it to the front
// 	t_list *new_node = ft_lstnew(p1);
// 	ft_lstadd_front(&head, new_node);
// 	new_node = ft_lstnew(p2);
// 	ft_lstadd_front(&head, new_node);
// 	new_node = ft_lstnew(p3);
// 	ft_lstadd_front(&head, new_node);
// 	print_list(head);
// 	t_list *tmp;
// 	while (head != NULL) {
// 		tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return 0;
// }