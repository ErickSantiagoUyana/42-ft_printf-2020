# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: euyana-b <euyana-b@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/08 13:42:26 by euyana-b          #+#    #+#              #
#    Updated: 2020/11/06 23:45:41 by euyana-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libftprintf.a

SRC		= ./*.c

OBJ		= $(SRC:.c=.o)
CFLAG	= -Wall -Wextra -Werror -g

all: $(NAME)

$(NAME):
	gcc $(CFLAG) -c $(SRC)
	ar -rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:		all clean fclean re
