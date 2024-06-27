/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_seq.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 20:06:45 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/27 20:22:16 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OP_SEQ_H
# define OP_SEQ_H

# include <stdlib.h>

t_op_seq	*op_seq_init();
void		op_seq_free(t_op_seq *op);
void		op_seq_push(t_op_seq *op, char *op_str);

#endif