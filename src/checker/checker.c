// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   checker.c                                          :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/29 05:01:36 by ssoeno            #+#    #+#             */
// /*   Updated: 2024/06/29 05:38:11 by ssoeno           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/push_swap.h"

// typedef struct s_list {
//     int value;
//     struct s_list *next;
// } t_list;

// t_list *init_stack(int argc, char **argv);
// void apply_operations(t_list **stack_a, t_list **stack_b);
// int is_sorted(t_list *stack);
// void free_stack(t_list *stack);

// int main(int argc, char **argv) {
//     if (argc < 2) {
//         printf("Usage: %s <numbers>... \n", argv[0]);
//         return 1;
//     }

//     t_list *stack_a = init_stack(argc, argv);
//     t_list *stack_b = NULL;

//     apply_operations(&stack_a, &stack_b);

//     if (is_sorted(stack_a)) {
//         printf("OK\n");
//     } else {
//         printf("KO\n");
//     }

//     free_stack(stack_a);
//     free_stack(stack_b);
//     return 0;
// }

// void apply_operations(t_list **stack_a, t_list **stack_b)
// {
//     char line[1024];  // 十分な長さを確保

//     while (fgets(line, sizeof(line), stdin)) {
//         line[strcspn(line, "\n")] = '\0';  // 改行文字を除去
//         if (strcmp(line, "pa") == 0) {
//             pa(stack_b, stack_a, NULL, true);
//         } else if (strcmp(line, "pb") == 0) {
//             pb(stack_a, stack_b, NULL, true);
//         } else if (strcmp(line, "ra") == 0) {
//             ra(stack_a, NULL, true);
//         } else if (strcmp(line, "rb") == 0) {
//             rb(stack_b, NULL, true);
//         } else if (strcmp(line, "rr") == 0) {
//             ra(stack_a, NULL, true);
//             rb(stack_b, NULL, true);
//         } else if (strcmp(line, "rra") == 0) {
//             rra(stack_a, NULL, true);
//         } else if (strcmp(line, "rrb") == 0) {
//             rrb(stack_b, NULL, true);
//         } else if (strcmp(line, "rrr") == 0) {
//             rrr(stack_a, NULL, true);
//             reverse_rotate_b(stack_b);
//         } else if (strcmp(line, "sa") == 0) {
//             sa(stack_a, NULL, true));
//         } else if (strcmp(line, "sb") == 0) {
//             sb(stack_b, NULL, true));
//         } else if (strcmp(line, "ss") == 0) {
//             sa(stack_a, NULL, true));
//             sb(stack_b, NULL, true));
//         } else {
//             fprintf(stderr, "Unknown operation: %s\n", line);
//         }
//     }
// }
