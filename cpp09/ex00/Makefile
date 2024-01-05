# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aaudevar <aaudevar@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/24 14:28:39 by aaudevar          #+#    #+#              #
#    Updated: 2023/06/23 13:24:22 by aaudevar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = 	main.cpp \
		BitCoinExchange.cpp \
		

OBJS = ${SRCS:.cpp=.o}

NAME = btc
CXX = c++
RM = rm -f
CFLAGS = -Wall -Wextra -Werror -std=c++98
HEADER = BitCoinExchange.hpp

%.o: %.cpp ${HEADER}
	${CXX} ${CFLAGS} -c $< -o ${<:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJS} ${HEADER}
	${CXX} ${CFLAGS} -o ${NAME} ${OBJS}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re