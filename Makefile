
NAME = fractol

SRC_PATH = src

SRC_NAME = ./cl.c ./error.c ./init.c ./jul.c ./key.c ./korabl.c ./main.c ./mand.c ./module.c ./mouse.c ./ohhh.c

CPPFLAGS = -I libft/includes/ -I /usr/local/include/ -MMD

LDFLAGS = -L libft/ -lft -lpthread

MLX_FLAGS = -I ./minilibx_macos/ ./minilibx_macos/libmlx.a

LDLIBS = -framework OpenGL -framework AppKit

CC = gcc

CFLAGS = -Werror -Wall -Wextra

OBJ_NAME = $(SRC_NAME:.c=.o)

OBJ_PATH = obj

HEADER_PATH = includes/

HEADER_NAME = fractol.h

OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))

HEADER = $(addprefix $(HEADER_PATH)/,$(HEADER_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft/
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(LDFLAGS) $(MLX_FLAGS) $(LDLIBS) $^ -o $@

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c | $(OBJ_PATH)
	$(CC) $(CFLAGS) $(CPPFLAGS) -I $(HEADER_PATH) -o $@ -c $<

$(OBJ_PATH):
	@mkdir $(OBJ_PATH) 2> /dev/null || true

clean:
	make clean -C libft/
	make clean -C minilibx_macos
	rm -f $(OBJ) $(OBJ:.o=.d)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	make fclean -C libft/
	make fclean -C minilibx_macos/
	rm -f $(NAME)

re: fclean
	$(MAKE) all

.PHONY: make clean fclean re

-include $(OBJ:.o=.d)