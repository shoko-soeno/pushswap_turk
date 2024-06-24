# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssoeno <ssoeno@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/28 00:30:25 by ssoeno            #+#    #+#              #
#    Updated: 2024/06/19 23:43:12 by ssoeno           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
BASIC_SRCS = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c \
ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
ft_atoi.c ft_calloc.c ft_strdup.c \
ft_strjoin.c ft_split.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c \
ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c
BONUS_SRCS = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

ifeq ($(BONUS_FLAG),yes)
	SOURCES = $(BASIC_SRCS) $(BONUS_SRCS)
else
	SOURCES = $(BASIC_SRCS)
endif
OBJS = $(SOURCES:.c=.o)

#default target
all: $(NAME)

#create static library
$(NAME): $(OBJS)
	$(AR) rcs $@ $^

#complile (source to object)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

#clean
clean:
	$(RM) $(BASIC_SRCS:.c=.o) $(BONUS_SRCS:.c=.o)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#bonus
bonus:
	$(MAKE) all BONUS_FLAG=yes

.PHONY : all clean fclean re bonus