# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gprada-t <gprada-t@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/19 15:58:21 by gprada-t          #+#    #+#              #
#    Updated: 2024/07/19 17:21:37 by gprada-t         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = FixedPoint

SRCS = Fixed.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(SRCS:.cpp=.d)

CC = c++
FLAGS = -Wall -Wextra -Werror -std=c++98 -g -MMD -MP

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

.PHONY: all clean fclean re

-include $(DEPS)
