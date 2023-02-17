# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/14 15:20:47 by hznagui           #+#    #+#              #
#    Updated: 2023/02/17 15:35:06 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

NAME_B = so_long_bonus

FLAGS = -Wall -Wextra -Werror

MAND = mandatory/

BON = bonus/

BNS_FILE = 	bonus/main_bonus.c \
			bonus/utils.bonus.c \
			bonus/utils__bonus.c \
			bonus/utils_bonus.c \
			bonus/utils1_bonus.c \
			bonus/utils2_bonus.c \
			bonus/utils3_bonus.c \
			bonus/error_bonus.c \
			
SRC_FILE = 	mandatory/utils.c \
			mandatory/utils1.c \
			mandatory/utils2.c \
			mandatory/utils__.c \
			mandatory/utils_.c \
			mandatory/error.c \
			mandatory/main.c \

OBJ_FILE = $(SRC_FILE:.c=.o)

OBJ_FILE_B = $(BNS_FILE:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ_FILE) mandatory/so_long.h 
	@cc $(FLAGS) $(OBJ_FILE) -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "--->[mandatory part successfully created ✅]<---"


bonus : $(NAME_B)

$(NAME_B): $(OBJ_FILE_B)  bonus/so_long_bonus.h 
	@cc $(FLAGS) $(OBJ_FILE_B) -lmlx -framework OpenGL -framework AppKit -o $(NAME_B)
	@echo "--->[bonus part successfully created ✅]<---"


$(MAND)%.o: $(MAND)%.c mandatory/so_long.h 
	@$(CC) $(FLAGS) -Imlx -c $< -o $@



$(BON)%.o: $(BON)%.c bonus/so_long_bonus.h
	@$(CC) $(FLAGS) -Imlx -c $< -o $@



clean :
	@rm -rf $(OBJ_FILE) $(OBJ_FILE_B)
	@echo "--->[obj file deleted successfully ✅]<---"

fclean: clean
	@rm -f $(NAME) $(NAME_B)
	@echo "--->[programs deleted successfully ✅]<---"


re : fclean all

	

