# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 19:53:43 by masharla          #+#    #+#              #
#    Updated: 2020/08/11 18:54:37 by etorren          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c map_create.c logic.c read_file.c helpers.c map_treat.c
BIN		= bsq
CONVO	= ${SRC:.c=.o}
FLAGS	= -Wall -Wextra -Werror
COMP	= gcc ${FLAGS}

.c.o:
	${COMP} -c $<

all: ${CONVO}
	gcc ${CONVO} -o ${BIN}

clean:
	rm -f ${CONVO}

fclean: clean
	rm -f ${BIN}

re: fclean all
