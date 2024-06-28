/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_seq.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:19:30 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/28 14:28:07 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_op_seq	*op_seq_init()
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
	op->arr[op->size] = op_str; //指定された文字列op_strを配列arrの次の空いている位置に追加
	op->size++;
}
//配列の範囲外アクセスに注意