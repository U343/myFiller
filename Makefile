# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wanton <wanton@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/18 12:03:06 by wanton            #+#    #+#              #
#    Updated: 2020/08/17 16:42:50 by wanton           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = wanton.filler

SRC_PATH = ./src/
LIB_PATH = ./libft/
INC_PATH = ./includes/ $(LIB_PATH)
HEAD_PATH = ./includes/

LIBFT = $(LIBFT_PATH)libft.a

SRC_FILES = main.c \
			get_next_line.c \
			parse_map.c \
			init_functions.c \
			free_functions.c \
			create_hot_map.c \
			find_place.c \
			cut_token.c

HEADERS_LIST = filler.h \
				get_next_line.h \
				constants.h

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SRC_FILES))
OBJ = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

FLAGS = -Wall -Wextra -Werror

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))
INC = $(addprefix -I, $(INC_PATH))
HEADERS = $(addprefix $(HEAD_PATH), $(HEADERS_LIST))

all: $(NAME)

$(NAME): $(OBJ)
		make -C $(LIB_PATH)
		gcc $(FLAGS) $(OBJ)  $(INC) -L $(LIB_PATH) -lft -o $(NAME)

$(OBJ): | $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SRC_PATH)%.c $(HEADERS)
		gcc $(FLAGS)  $(INC) -c $< -o $@


clean:
		make -C $(LIB_PATH)/ clean
		/bin/rm -rf $(OBJECTS_DIRECTORY)

fclean: clean
		make -C $(LIB_PATH)/ fclean
		/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re