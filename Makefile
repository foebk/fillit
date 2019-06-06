# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ction <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/11 18:06:10 by ction             #+#    #+#              #
#    Updated: 2019/04/13 13:00:10 by ction            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
SRC = alexey.c pajitnov.c fillit.c validation.c whatthefigure.c
OBJ = $(SRC:.c=.o)
LIBFT = libft/libft.a
HEADER = -c -I fillit.h

all: $(NAME)

$(OBJ): %.o: %.c
		@gcc -c -Wall -Werror -Wextra -I./libft/includes $< -o $@

$(LIBFT):
	@make -C libft

$(NAME): $(LIBFT) $(OBJ)
	@gcc $(OBJ) $(LIBFT) -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	@make -C libft clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft fclean

re: fclean all
