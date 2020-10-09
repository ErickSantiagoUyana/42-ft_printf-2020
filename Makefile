# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 13:42:26 by euyana-b          #+#    #+#              #
#    Updated: 2020/10/09 21:59:59 by euyana-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./srcs/*.c ./libft/*.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror
HEADER	= includes/

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c -I$(HEADER) -I ./libft $(SRC)
	ar rc $(NAME) *.o
	ranlib $(NAME)

test:
	@make all ./srcs/main.c

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
