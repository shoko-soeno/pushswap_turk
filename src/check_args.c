/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:18:46 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 19:55:36 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	long	ret;
	long	sign;

	ret = 0l;
	sign = 1l;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign = -1l;
	while (ft_isdigit(*str))
	{
		if (ret > LONG_MAX / 10 || (ret == LONG_MAX / 10 && *str > '7'))
			return (LONG_MAX);
		if (ret < LONG_MIN / 10 || (ret == LONG_MIN / 10 && *str > '8'))
			return (LONG_MIN);
		ret = ret * 10l + (*str++ - '0') * sign;
	}
	return (ret);
}

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atoi(argv[i]) == num)
			return (1);
		i++;
	}
	return (0);
}

bool	ft_isnum(char *num)
{
	size_t	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
	if (num[i] == '\0')
		return (false);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (false);
		i++;
	}
	return (true);
}

bool	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	if (argc == 2)
		args = ft_split(argv[1], ' ');
	else
		args = argv + 1;
	i = 0;
	while (args[i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || ft_duplicate(tmp, args, i)
			|| tmp < INT_MIN || tmp > INT_MAX)
		{
			if (argc == 2)
				ft_free(args);
			return (false);
		}
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (true);
}
