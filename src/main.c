/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/29 01:37:38 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack_a_from_args(t_node **stack, int argc, char **argv)
{
	t_node	*new;
	char	**values;
	size_t	i;

	i = 0;
	values = NULL;
	if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
		if (!values)
			return ;
	}
	else
	{
		i = 1;
		values = argv;
	}
	while (values[i])
	{
		new = ft_lstnew(ft_atoi(values[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	if (argc == 2)
		ft_free(values);
}

static void	sort_stack(t_node **stack_a, t_node **stack_b, t_op_seq *op)
{
	size_t	lstsize;

	(void) **stack_b;
	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 3)
		sort_small(stack_a, lstsize, op);
	else
		turk_sort(stack_a, stack_b, op);
}

int	main(int argc, char *argv[])
{
	t_node		**stack_a;
	t_node		**stack_b;
	t_op_seq	*op;

	if (argc < 2)
		return (1);
	if (!ft_check_args(argc, argv))
	{ // "+5"はinvalid, "-"だけもvalidになってしまっているので、修正が必要
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stack_a = (t_node **)malloc(sizeof(t_node *)); //なぜかここがsizeof(t_node）になってた
	stack_b = (t_node **)malloc(sizeof(t_node *));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), 1); //mallocの失敗はチェックしないとnull参照してしまう！
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack_a_from_args(stack_a, argc, argv);
	op = op_seq_init();
	if (is_sorted(*stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b, op);
	print_node(*stack_a); //debug
	for (int i = 0; i < op->size; i++)
		printf("%s\n", op->arr[i]); //あとでprintfを別の関数に置換する
	free_stack(stack_a);
	free_stack(stack_b);
	op_seq_free(op);
	return (0);
}
/*
コマンドライン引数のエラーハンドリング（特に2つ以上のコマンドライン引数が渡された時のError出力）
./push_swap a でエラーが出ないように修正する
連結リストの操作でnullチェックが漏れておりメモリリークが防げていない
long_maxやlong_minでオーバーフローした時に適切に処理されていない
is_num +は弾かなくていいかも。数字が一つでも含まれているかどうかのチェックは必須
operationの出力はまとめて行った方が良い
*/