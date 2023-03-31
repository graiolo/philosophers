# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: graiolo <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/08 15:08:41 by graiolo           #+#    #+#              #
#    Updated: 2023/03/31 12:21:14 by graiolo          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	philo

CC		=	cc

CFLAGS	=	-Wall -Werror -Wextra -g -Wuninitialized -pthread

SDIR	=	./src/

SRC		=	main.c \
				ft_create_init.c \
				ft_action.c ft_solo_action.c \
				ft_time.c  ft_message.c ft_utils.c \
				ft_init_destoi.c

SRCS	= 	$(addprefix $(SDIR), $(SRC))

ODIR	=	./obj/

OBJ		=	$(SRC:.c=.o)

OFILE	=	$(addprefix $(ODIR), $(OBJ))

$(ODIR)%.o : $(SDIR)%.c philo.h
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
