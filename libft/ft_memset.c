/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:15:01 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/28 13:25:27 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*ptr;

	if (b == NULL)
		return (NULL);
	if (len == 0)
		return (b);
	ptr = (unsigned char *)b;
	while (len-- > 0)
		*ptr++ = (unsigned char)c;
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char buffer[10];
// 	// void *p1 = memset(buffer, 'x', NULL);
// 	// printf("p1: %p\n", p1);
// 	void *p2 = ft_memset(buffer, 'x', 0);
// 	printf("p2: %p\n", p2);
// 	// for (int i = 0; i < 10; i++)
// 	// {
// 	// 	printf("%c", buffer[i]);
// 	// }
// 	// printf("\n");
// }