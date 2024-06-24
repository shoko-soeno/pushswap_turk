/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 00:28:49 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/30 21:38:58 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	i;

	dst_len = 0;
	if (dst)
		dst_len = ft_strlen(dst);
	if (dstsize <= dst_len || dstsize == 0)
		return (dstsize + ft_strlen(src));
	i = 0;
	while (src[i] != '\0' && dst_len + i < dstsize - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	if (dst_len < dstsize)
		dst[dst_len + i] = '\0';
	return (dst_len + ft_strlen(src));
}

// int main() {
// 	char dst[10] = "Hello";
// 	const char *src = " World!";
// 	size_t result;
// 	//result = ft_strlcat(NULL, src, sizeof(dst));
// 	//result = strlcat(NULL, src, sizeof(dst));
// 	//result = ft_strlcat(NULL, src, sizeof(dst));
// 	result = strlcat(NULL, src, 0);
// 	//result = ft_strlcat(NULL, src, 0);
// 	printf("Return value: %zu\n", result);
// 	printf("Result = %s\n", &*dst);
// 	return 0;
// }