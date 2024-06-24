/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 21:57:58 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/18 19:33:55 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_char(char *s, unsigned int number, long int len)
{
	while (number > 0)
	{
		s[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (s);
}

static long int	ft_int_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len = 1;
	while (n != 0)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char				*s;
	long int			int_len;
	unsigned int		number;

	int_len = ft_int_len(n);
	s = (char *)malloc(sizeof(char) * (int_len + 1));
	if (!(s))
		return (NULL);
	s[int_len--] = '\0';
	if (n == 0)
		s[0] = '0';
	if (n < 0)
	{
		number = n * -1;
		s[0] = '-';
	}
	else
		number = n;
	s = ft_char(s, number, int_len);
	return (s);
}

// int main()
// {
// 	int test_values[] = {1234, -1234, 0, 2147483647, -2147483648};
// 	char *result;
// 	for (int i = 0; i < sizeof(test_values) / sizeof(test_values[0]); i++) {
// 		result = ft_itoa(test_values[i]);
// 		printf("ft_itoa(%d) = %s\n", test_values[i], result);
// 		free(result);  // Remember to free the allocated memory
// 	}
// 	return 0;
// }
