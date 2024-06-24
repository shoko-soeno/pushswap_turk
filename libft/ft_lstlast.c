/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:35:26 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/22 20:13:03 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// int main() {
// 	t_list *head = NULL;
// 	t_list *last;
// 	int *p1 = malloc(sizeof(int));
// 	int *p2 = malloc(sizeof(int));
// 	int *p3 = malloc(sizeof(int));
// 	if(p1 == NULL || p2 == NULL || p3 == NULL){
// 		return -1;
// 	}
// 	*p1 = 42;
// 	*p2 = 43;
// 	*p3 = 44;
// 	head = ft_lstnew(p1);
// 	head->next = ft_lstnew(p2);
// 	head->next->next = ft_lstnew(p3);
// 	last = ft_lstlast(head);
// 	if (last != NULL && last->content == p3)
// 		printf("Last content is 44.\n");
// 	// clean lists
// 	while (head != NULL) {
// 		t_list *tmp = head;
// 		head = head->next;
// 		free(tmp);
// 	}
// 	return 0;
// }