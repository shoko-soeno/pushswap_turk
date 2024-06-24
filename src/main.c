/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 20:25:32 by ssoeno            #+#    #+#             */
/*   Updated: 2024/06/24 14:01:36 by ssoeno           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	init_stack(t_list **stack, int argc, char **argv)
{
	t_list	*new;
	char	**values;
	size_t	i;

	i = 0;
	values = NULL;
	if (argc == 2)
	{
		values = ft_split(argv[1], ' ');
		if (!values) //ft_splitの返り値がNULLの場合のエラーハンドリングは？
			return ;
	}
	else
	{
		i = 1;
		values = argv;
	}
	while (values && values[i]) //splitの後にNULLチェックしていれば、ここのNULLチェックは不要
	{
		new = ft_lstnew(ft_atoi(values[i]));
		ft_lstadd_back(stack, new);
		i++;
	}
	index_compression(stack);
	if (argc == 2 && values)
		ft_free(values); //ft_freeの中でNULLチェックしているなら、このNULLチェックは不要
}

static void	sort_stack(t_list **stack_a, t_list **stack_b)
{
	size_t	lstsize;

	lstsize = ft_lstsize(*stack_a);
	if (lstsize <= 5)
		sort_small(stack_a, stack_b, lstsize);
	else
		radix_sort(stack_a, stack_b, lstsize);
}

// #include <libc.h>
// __attribute__((destructor))
// static void destructor() {
//     system("leaks -q push_swap");
// }
int	main(int argc, char *argv[])
{
	t_list	**stack_a;
	t_list	**stack_b;

	if (argc < 2)
		return (1);
	if (!ft_check_args(argc, argv)) // "+5"はinvalid, "-"だけもvalidになってしまっているので、修正が必要
		ft_putstr_fd("Error\n", 2);
		return (1);
	stack_a = (t_list **)malloc(sizeof(t_list *)); //なぜかここがsizeof(t_list）になってた
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (!stack_a || !stack_b)
		return (free(stack_a), free(stack_b), 1); //mallocの失敗はチェックしないとnull参照してしまう！
	*stack_a = NULL;
	*stack_b = NULL;
	init_stack(stack_a, argc, argv);
	if (is_sorted(stack_a))
	{
		free_stack(stack_a);
		free_stack(stack_b);
		return (0);
	}
	sort_stack(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
/*
radix sortで、座標圧縮後の値を使えば最大桁が効率よく求められる
コマンドライン引数のエラーハンドリング（特に2つ以上のコマンドライン引数が渡された時のError出力）
./push_swap a でエラーが出ない
連結リストの操作でnullチェックが漏れておりメモリリークが防げていない
long_maxやlong_minでオーバーフローした時に適切に処理されていない
座標圧縮はnlognのソートを行ってからインデックスを振った方が効率が良い。重複チェックもソート後に行った方が良い。
is_num +は弾かなくていいかも。数字が一つでも含まれているかどうかのチェックは必須
operationの出力はまとめて行った方が良いこと（raとrbが続いたらrrとすれば手数が減らせる）
*/