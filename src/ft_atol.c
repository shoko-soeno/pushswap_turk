/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/19 23:18:46 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/24 19:59:15 by ssoeno           ###   ########.fr       */
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

long	ft_atol(const char *str)
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
