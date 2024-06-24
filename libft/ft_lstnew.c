/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:35:56 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 00:01:23 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"

// t_list	*ft_lstnew(void *value)
// {
// 	t_list	*new_node;

// 	new_node = (t_list *)malloc(sizeof(t_list));
// 	if (!new_node)
// 		return (NULL);
// 	new_node->value = value;
// 	new_node->next = NULL;
// 	return (new_node);
// }

// int main() {
//     int num = 42;
//     t_list *node1 = ft_lstnew(&num);
//     printf("Test 1 Passed: %d\n", *(int *)(node1->value));
//     char *str = "Hello, World!";
//     t_list *node2 = ft_lstnew(str);
//     printf("Test 2 Passed: %s\n", (char *)(node2->value));
//     free(node1);
//     free(node2);
//     return 0;
// }