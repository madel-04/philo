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

SRC			= src/health_monitor.c \
				src/main.c \
				src/philo_actions.c \
				src/philo_threads.c \
				src/simulation_init.c \
				utils/functions.c \
				utils/parse_args.c \
				utils/print_status.c \
				utils/utils.c \
				utils/validate_X_args.c \

OBJ			= $(SRC:%.c=%.o)

INCLUDE		= include/philo.h

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
