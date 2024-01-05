# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 14:28:39 by aaudevar          #+#    #+#              #
#    Updated: 2023/02/08 18:21:24 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \
		AAnimal.cpp \
		Dog.cpp \
		Cat.cpp \
		Brain.cpp \
		

OBJS = ${SRCS:.cpp=.o}

NAME = brain
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