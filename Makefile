# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/18 21:20:45 by ssoeno            #+#    #+#              #
#    Updated: 2024/06/29 05:47:56 by ssoeno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CHECK = checker

CC = cc
# CFLAGS = -g -Wall -Werror -Wextra -fsanitize=address -O3 -MMD -MP -Iincludes
CFLAGS = -Wall -Werror -Wextra -Iincludes

LIBFT = ./libft
CHECKER	= checker
SRCS =  $(wildcard src/*.c src/operations/*.c src/algorithm/*.c) 
# wildcard は使用禁止！
# option + click でコマンドの好きな場所を選択できる
# ARG=`jot -r 10 1 100 | tr '\n' ' '`; ./push_swap $ARG
# CHECK_SRCS = $(wildcard utils/*.c) src/operations.c checker.c

OBJS = $(SRCS:.c=.o)
CHECKER_OBJ	=  $(CHECKER_SRC:%.c=src/checker/%.o)
# DEPS=$(SRCS:.c=.d)

all: $(NAME)

# bonus:$(CHECKER)

obj:
	mkdir -p obj

# -include $(OBJS:.o=.d)

$(NAME): $(OBJS)
	@$(MAKE) -C $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT) -lft -o $(NAME)

# $(CHECK): $(CHECK_OBJS)
# 	@$(MAKE) -C $(LIBFT)
# 	@$(CC) $(CFLAGS) $(CHECK_OBJS) -L$(LIBFT) -lft -o $(CHECK)

clean:
	make -C ./libft fclean
	@$(RM) $(OBJS)
	@$(RM) $(CHECK_OBJS)
	@$(RM) $(OBJS) $(OBJS:.o=.d)
	$(RM) -r obj

fclean: clean
	make -C $(LIBFT) fclean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re