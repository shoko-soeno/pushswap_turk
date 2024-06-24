/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 20:07:00 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/27 07:19:18 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (!dst || !src)
		return (dst);
	if (dst < src)
		return (ft_memcpy(dst, src, len));
	while (len > 0)
	{
		d[len - 1] = s[len - 1];
		len--;
	}
	return (dst);
}

// int main()
// {
// 	//char src[100] = "";
// 	char dest[100];
// 	// NULL
// 	void *result = ft_memmove(dest, NULL, 10);  // void * で型を一般化
// 	if (result == NULL) {
// 		printf("NULL pointer given: %p\n", result);
// 	} else {
// 		printf("Unexpected behavior with NULL pointers.\n");
// 	}
// 	// Overlap
// 	char overlap_src[8] = "apple";
// 	ft_memmove(overlap_src + 2, overlap_src, 3);
// 	printf("Overlap simulation: %s\n", overlap_src);
// 	return 0;
// }
// overlapexample
// pexamplexample