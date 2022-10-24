# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tfedoren <tfedoren@student.42wolfsburg.de> +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/08 18:59:54 by tfedoren          #+#    #+#              #
#    Updated: 2022/10/24 17:51:05 by tfedoren         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

SRC =	main.c \
		check_input.c \
		helpers.c \
		time.c \
		init.c \
		create_threads.c \
		join_threads_and_destroy_mutexes.c \
		someone_died.c \
		routine_functions.c

CC = gcc
CFLAGS = -Wall -Wextra -Werror  #-fsanitize=address -g -O1
RM = rm -rf

all: 
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) 
	
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus

#-fsanitize=thread -g -O1