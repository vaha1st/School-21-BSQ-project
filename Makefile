# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 19:53:43 by masharla          #+#    #+#              #
#    Updated: 2020/08/12 11:51:39 by masharla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c map_create.c logic.c helpers.c map_treat.c\
		  std_input.c file_service.c
BIN		= bsq
CONVO	= ${SRC:.c=.o}
FLAGS	= -Wall -Wextra -Werror
COMP	= gcc ${FLAGS} -Iheaders

.c.o:
	${COMP} -c $<

all: ${CONVO}
	gcc ${CONVO} -o ${BIN}

clean:
	rm -f ${CONVO}
	rm -f std_input_file

fclean: clean
	rm -f ${BIN}

re: fclean all
