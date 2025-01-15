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

NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread
OBJ_DIR = obj/
SRC_DIR = src/
UTILS_DIR = utils/
INCLUDES = -I include/

SRC = $(SRC_DIR)health_monitor.c \
      $(SRC_DIR)main.c \
      $(SRC_DIR)philo_actions.c \
      $(SRC_DIR)philo_threads.c \
      $(SRC_DIR)simulation_init.c \
      $(UTILS_DIR)functions.c \
      $(UTILS_DIR)parse_args.c \
      $(UTILS_DIR)print_status.c \
      $(UTILS_DIR)utils.c \
      $(UTILS_DIR)validate_X_arg.c \

OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(notdir $(SRC)))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(INCLUDES) -o $(NAME) $(OBJ)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)%.o: $(UTILS_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
