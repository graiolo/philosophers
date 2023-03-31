# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 19:00:15 by graiolo           #+#    #+#              #
#    Updated: 2023/03/30 19:36:09 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    =   philo_bonus

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g -Wuninitialized -pthread

SDIR	=	./src/

SRC		=	main.c \
				ft_create_init_bonus.c \
				ft_action_bonus.c \
				ft_time_bonus.c  ft_message_bonus.c ft_utils_bonus.c \
				ft_init_destroy_bonus.c

SRCS	= 	$(addprefix $(SDIR), $(SRC))

ODIR	=	./obj/

OBJ		=	$(SRC:.c=.o)

OFILE	=	$(addprefix $(ODIR), $(OBJ))

$(ODIR)%.o : $(SDIR)%.c philo_bonus.h
	@mkdir -p $(ODIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\e[0;33m$< ----> $@\e[0;m"

all:	$(NAME)

$(NAME):	$(OFILE)
	@$(CC) $(CFLAGS) $(OFILE) -o $(NAME)
	@echo "\e[0;32mcompilato!\e[0;m"

clean:	
	@rm -rf $(OFILE)
	@echo "\e[0;31mtutto obj rimossi\e[0;m"


fclean:	clean
	@rm -rf $(NAME)
	@echo "\e[0;31m$(NAME) rimosso\e[0;m"

test: all clean

re: fclean all

.PHONY: all clean fclean re
