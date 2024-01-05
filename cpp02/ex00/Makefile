# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 14:28:39 by aaudevar          #+#    #+#              #
#    Updated: 2023/01/31 10:39:03 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \
		Fixed.cpp \
		

OBJS = ${SRCS:.cpp=.o}

NAME = fixed
CXX = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98

%.o: %.c
	${CXX} ${CFLAGS} -c $< -o ${<:.c=.o}

all: ${NAME}

${NAME}: ${OBJS}
	${CXX} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re