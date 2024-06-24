/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:18:46 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/24 14:43:40 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	handle_overflow(const char *str, int sign)
{
	unsigned long	ret;
	int				digit;
	unsigned long	cutoff;

	ret = 0;
	cutoff = (unsigned long)LONG_MAX;
	while (ft_isdigit(*str))
	{
		digit = *str - '0';
		if (sign == 1 && ret > ((cutoff - digit) / 10))
			return (LONG_MAX);
		if (sign == -1 && ret > ((cutoff + 1 - digit) / 10))
			return (LONG_MIN);
		ret = ret * 10 + digit;
		str++;
	}
	return (ret);
}

static int	is_space(const char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

static long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	result = (int)handle_overflow(str, sign);
	return ((sign * result));
}

static int	ft_duplicate(int num, char **argv, int i)
{
	i++;
	while (argv[i])
	{
		if (ft_atol(argv[i]) == num)
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
	if (!num[i])
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
	while (args[++i])
	{
		tmp = ft_atol(args[i]);
		if (!ft_isnum(args[i]) || ft_duplicate(tmp, args, i)
			|| tmp < INT_MIN || tmp > INT_MAX)
		{
			if (argc == 2)
				ft_free(args);
			return (false);
		}
	}
	if (argc == 2)
		ft_free(args);
	return (true);
}
