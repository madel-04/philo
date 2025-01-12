# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/30 22:06:32 by marvin            #+#    #+#              #
#    Updated: 2024/12/30 22:06:32 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR			= ar rcs
RM			= rm -f
CC			= cc
CFLAGS		= -Wall -Wextra -Werror
NAME		= philosophers

SRC			= functions/init.c \
				functions/main.c \
				functions/parsing.c \
				functions/utils.c \

OBJ			= $(SRC:%.c=%.o)

INCLUDE		= include/philosopher.h

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
		$(AR) $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean fclean re

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
