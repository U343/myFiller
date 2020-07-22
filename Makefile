# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wanton <wanton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 12:03:06 by wanton            #+#    #+#              #
#    Updated: 2020/07/22 14:37:26 by wanton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wanton.filler

SRC_PATH = ./src/
LIB_PATH = ./libft/
OBJ_PATH = ./obj/
INC_PATH = ./includes/ $(LIB_PATH)

SRC_FILES = main.c \
			get_next_line.c \
			write_trace.c \
			parse_map.c

OBJ_FILES = $(SRC_FILES:.c=.o)

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)
		gcc $(FLAGS) $(OBJ)  $(INC) -L $(LIB_PATH) -lft -o $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
		mkdir -p $(OBJ_PATH)
		gcc $(FLAGS)  $(INC) -c $< -o $@

clean:
		make -C $(LIB_PATH)/ clean
		/bin/rm -rf $(OBJ_PATH)

fclean: clean
		make -C $(LIB_PATH)/ fclean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re $(NAME)