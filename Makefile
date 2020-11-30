# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/08 10:12:58 by xlongfel          #+#    #+#              #
#    Updated: 2019/11/26 14:44:20 by xlongfel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, $(NAME), clean, fclean, re

NAME = fractol

SRCS = ./cl.c ./init.c ./jul.c ./key.c ./main.c ./mand.c ./ohhh.c

INC = -I includes/fractol.h -I libft/

LIB = -L minilibx_macos/ -l mlx -L libft/ -lft

FRM = -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	@mkdir -p obj/
	@make -C minilibx_macos
	@make -C libft
	@gcc -Wall -Werror -Wextra -c $(SRCS) $(INC)
	@mv *.o obj/
	@gcc obj/*.o $(LIB) -o $(NAME) $(FRM)

clean:
	@make -C minilibx_macos/ clean
	@make -C libft/ clean
	@rm -rf obj/

fclean: clean
	@make -C libft/ fclean
	@rm -rf $(NAME)

re: fclean all