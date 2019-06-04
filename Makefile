# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jwinthei <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/20 13:26:35 by jwinthei          #+#    #+#              #
#    Updated: 2018/12/20 17:38:07 by jwinthei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= fillit

SRC	= fillit.c valid_checkers.c tetr_rewriters.c

OBJ = $(SRC:.c=.o)

INCL= libft/includes/

LIB = libft/ -lft

FLG = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	gcc -c $(SRC) -I $(INCL) $(FLG)
	gcc -o $(NAME) $(OBJ) -I $(INCL) -L $(LIB) $(FLG)

clean:
	rm -f *.o
	make -C libft/ clean

fclean: clean
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all
