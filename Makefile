# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:20:47 by hznagui           #+#    #+#              #
#    Updated: 2023/02/16 15:28:35 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

FLAGS = -Wall -Wextra -Werror

MAND =

BON = 

BNS_FILE = 	bonus/main_bonus.c \
			bonus/utils.bonus.c \
			bonus/utils__bonus.c \
			bonus/utils_bonus.c \
			bonus/error_bonus.c \
			
SRC_FILE = 	mandatory/main.c \
			mandatory/utils.c \
			mandatory/utils__.c \
			mandatory/utils_.c \
			mandatory/error.c \

OBJ_FILE = $(SRC_FILE:.c=.o)
OBJ_FILE_B = $(BNS_FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILE) mandatory/so_long.h $(MAND)
	cc $(FLAGS) $(OBJ_FILE) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(OBJ_FILE_B) bonus/so_long_bonus.h 
	cc $(FLAGS) $(OBJ_FILE_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(MAND)%.o: %.c mandatory/so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

$(BON)%.o: %.c bonus/so_long_bonus.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ_FILE) $(OBJ_FILE_B)

fclean: clean
	rm -f $(NAME) $(NAME_B)

re : fclean all

	

