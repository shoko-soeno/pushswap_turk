/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:18:46 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/24 20:09:12 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	while (num[0] == '-' || num[0] == '+')
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

int	ft_check_args(int argc, char **argv)
{
	int		i;
	long	tmp;
	char	**args;

	i = 0;
	while (argv[++i])
	{
		tmp = ft_atol(argv[i]);
		if (!ft_isnum(argv[i]) || ft_duplicate(tmp, argv, i)
			|| tmp < INT_MIN || tmp > INT_MAX)
		{
			return (false);
		}
	}
	return (true);
}
