/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:53:02 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/25 18:05:26 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	s_len;
	size_t	finish;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	finish = 0;
	if (start < s_len)
		finish = s_len - start;
	if (finish > len)
		finish = len;
	new = (char *)malloc(sizeof(char) * (finish + 1));
	if (!new)
		return (NULL);
	ft_strlcpy(new, s + start, finish + 1);
	return (new);
}

// int main() {
// 	const char *text = "Hello, World!";
// 	char *substring;
// 	// test1
// 	substring = ft_substr(text, 7, 5);
// 	printf("normal case: '%s'\n", substring);
// 	free(substring);
// 	// test2 `start` is longer than s
// 	substring = ft_substr(text, 20, 5);
// 	printf("`start` is longer than s: '%s'\n", substring);
// 	free(substring);
// 	// test3 len is longer than needed
// 	substring = ft_substr(text, 0, 50);
// 	printf("`len` is longer than needed: '%s'\n", substring);
// 	free(substring);
// 	return 0;
// }