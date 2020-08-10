# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masharla <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/08/09 19:53:43 by masharla          #+#    #+#              #
#    Updated: 2020/08/10 10:36:20 by masharla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC		= main.c logic.c read_file.c helpers.c
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
