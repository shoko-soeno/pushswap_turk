/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 10:35:03 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/20 00:00:36 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	(*del)(lst->value);
	free(lst);
}

// void del_function(void *content) {
//     free(content);
// }
// int main() {
//     char *content = ft_strdup("Hello, World!");
//     t_list *node = ft_lstnew(content);
//     ft_lstdelone(node, del_function);
//     printf("Node and its content have been deleted.\n");
//     return 0;
// }››ß