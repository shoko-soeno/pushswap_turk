// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   checker_utils.c                                    :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/06/29 05:01:31 by ssoeno            #+#    #+#             */
// /*   Updated: 2024/06/29 05:33:11 by ssoeno           ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "../../includes/push_swap.h"

// int	get_next_line_ps(int fd, char *line)
// {
// 	int		i;
// 	int		read_status;
// 	char	char_buffer;

// 	i = 0;
// 	char_buffer = ' ';
// 	while (char_buffer != '\n')
// 	{
// 		read_status = read(fd, &char_buffer, 1);
// 		if (read_status == -1)
// 			return (EXIT_FAILURE);
// 		if (read_status == 0)
// 			break ;
// 		line[i++] = char_buffer;
// 		if (i > 4)
// 			return (EXIT_FAILURE);
// 	}
// 	if ((i > 0 && line[i - 1] != '\n') || line[0] == '\n')
// 		return (EXIT_FAILURE);
// 	if (read_status == 0)
// 		line[0] = '\0';
// 	else
// 		line[i - 1] = '\0';
// 	return (EXIT_SUCCESS);
// }

