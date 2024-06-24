/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:00:51 by ssoeno            #+#    #+#             */
/*   Updated: 2024/04/28 18:57:51 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*free_array(char **arr, size_t i)
{
	while (i > 0)
	{
		i--;
		free(arr[i]);
	}
	free(arr);
	return (NULL);
}

static int	count_words(char const *str, char c)
{
	size_t	i;
	int		cnt;

	i = 0;
	cnt = 0;
	if (!str || !c)
		return (-1);
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
			cnt++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (cnt);
}

static char	*ft_strndup(const char *src, size_t n)
{
	size_t	i;
	char	*dup;

	if (!src)
		return (NULL);
	dup = (char *)malloc((n + 1) * sizeof(char));
	if (!dup)
		return (NULL);
	i = 0;
	while (i < n && src[i])
	{
		dup[i] = src[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	**ft_split(char const *s, char c)
{
	char		**result;
	size_t		i;
	const char	*start;

	if (!s)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		start = s;
		while (*s != c && *s)
			s++;
		result[i] = ft_strndup(start, s - start);
		if (!result[i++])
			return (free_array(result, i - 1), NULL);
	}
	result[i] = NULL;
	return (result);
}

// int main (){
// 	char *s = ",,,hello,,,world,,,42,,,tokyo,,,,";
// 	char **result = ft_split(s, ',');
// 	char **temp = result;
// 	while (*temp)
// 	{
// 		printf("%s\n", *temp);
// 		temp++;
// 	}
// 	free(result);
// }
//malloc(0) returns NULL. if s is NULL, count_words(s,c) returns -1.