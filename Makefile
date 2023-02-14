# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:20:47 by hznagui           #+#    #+#              #
#    Updated: 2023/02/14 18:25:26 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = mandatory/so_long_bonus

FLAGS = -Wall -Wextra -Werror

MAND =

BON = 

SRC_FILE = 	mandatory/main.c \
			mandatory/utils.c \
			mandatory/utils__.c \
			mandatory/utils_.c \

OBJ_FILE = $(SRC_FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILE) mandatory/so_long.h $(MAND)
	cc $(FLAGS) $(OBJ_FILE) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

bonus : $(OBJ_FILE_B) bonus/so_long_bonus.h 
	cc $(FLAGS) $(OBJ_FILE_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)

$(MAND)%.o: %.c mandatory/so_long.h
	$(CC) $(FLAGS) -Imlx -c $< -o $@

# $(BON)%.o: %.c mandatory/so_long_bonus.h
# 	$(CC) $(FLAGS) -Imlx -c $< -o $@

clean :
	rm -rf $(OBJ_FILE)

fclean: clean
	rm -f $(NAME)

re : fclean all

	

