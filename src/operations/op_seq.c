/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:19:30 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 17:15:18 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

t_op_seq	*op_seq_init(void)
{
	t_op_seq	*op;

	op = (t_op_seq *)malloc(sizeof(t_op_seq));
	if (!op)
		return (NULL);
	op->size = 0;
	return (op);
}

void	op_seq_free(t_op_seq *op)
{
	free(op);
}

void	op_seq_add(t_op_seq *op, char *op_str)
{
	op->arr[op->size] = op_str;
	op->size++;
}
