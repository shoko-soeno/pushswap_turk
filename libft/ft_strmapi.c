/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 22:02:50 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/27 06:38:55 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	length;
	char			*res;

	if (!s || !f)
		return (NULL);
	length = ft_strlen(s);
	res = malloc(sizeof(char) * length + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < length)
	{
		res[i] = (*f)(i, s[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}

// char toupper_adapter(unsigned int index, char c) {
// 	(void)index;
// 	return (char)ft_toupper((int)c);
// }
// int main() {
// 	const char *input = "hello world";
// 	char *result;
// 	result = ft_strmapi(input, toupper_adapter);
// 	printf("Original: %s\n", input);
// 	printf("Uppercase: %s\n", result);
// 	free(result);
// 	return 0;
// }