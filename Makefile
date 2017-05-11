# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jschotte <jschotte@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/07 17:32:23 by jschotte          #+#    #+#              #
#    Updated: 2017/05/10 14:50:55 by jschotte         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
FLAGS = -Wall -Werror -Wextra
LIB = "libft/libft.a"
MLX =  "minilibx/libmlx.a"

SRC = main.c env.c fractal.c triangle.c hook.c julia.c mandel.c abs.c close.c
OBJ = main.o env.o fractal.o triangle.o hook.o julia.o mandel.o abs.o close.o

all: $(NAME)

$(NAME):
	make -C libft/ fclean && make -C libft/
	make -C minilibx/
	gcc $(FLAGS) -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB) $(MLX) -framework OpenGL -framework AppKit -o fractol

clean:
	make -C libft/ clean
	make -C minilibx/ clean
	rm -rf $(OBJ)

fclean: clean
	make -C libft/ fclean
	rm -rf $(NAME)

re: fclean all
