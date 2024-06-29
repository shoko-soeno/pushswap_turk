/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 17:22:27 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_stack_a_from_args(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	char	**values;
	size_t	i;

	i = 0;
	if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
		if (!values)
			return (-1);
	}
	else
		values = argv + 1;
	while (values && values[i])
	{
		new = ft_lstnew(ft_atoi(values[i]));
		if (!new)
			return (ft_free(values), -1);
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(values);
	return (0);
}

static void	sort_stack(t_node **stack_a, t_node **stack_b, t_op_seq *op)
{
	size_t	lstsize;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 3)
		sort_small(stack_a, lstsize, op);
	else
		turk_sort(stack_a, stack_b, op);
}

static void	output_operations(t_op_seq *op)
{
	int	i;

	i = 0;
	while (i < op->size)
	{
		ft_putendl_fd(op->arr[i], 1);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_node		**stack_a;
	t_node		**stack_b;
	t_op_seq	*op;

	if (argc < 2)
		return (1);
	if (!ft_check_args(argc, argv))
		return (ft_putstr_fd("Error\n", 2), 1);
	stack_a = (t_node **)malloc(sizeof(t_node *));
	stack_b = (t_node **)malloc(sizeof(t_node *));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), 1);
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack_a_from_args(stack_a, argc, argv);
	if (is_sorted(*stack_a))
		return (free_stack(stack_a), free_stack(stack_b), 0);
	op = op_seq_init();
	sort_stack(stack_a, stack_b, op);
	output_operations(op);
	free_stack(stack_a);
	free_stack(stack_b);
	op_seq_free(op);
	return (0);
}
