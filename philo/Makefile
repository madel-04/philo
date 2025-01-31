# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 18:23:40 by marvin            #+#    #+#              #
#    Updated: 2025/01/27 13:34:01 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
OBJ_DIR = obj/
SRC_DIR = src/
INCLUDES = -I include/
SRC = 	$(SRC_DIR)main.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)init.c \
		$(SRC_DIR)threads.c \
		$(SRC_DIR)monitor.c \
		$(SRC_DIR)routine_actions.c

CFLAGS = -Wall -Wextra -Werror -pthread -g
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(SRC)))


# SANITIZER = -fsanitize=thread // -fsanitize=address
# valgrind --tool=helgrind ./philo 5 800 200 200 2
# valgrind --tool=drd ./philo 5 800 200 200 3

.PHONY: all clean fclean re debug

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@
	
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

