NAME = fdf
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(wildcard $(SRC_DIR)/%.c))
DEPS = $(OBJECTS:.o=.d)

all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -Ilibft -I./mlx_linux -c $< -o $@ -I $(INC_DIR)

${NAME}: ${OBJS}
	@make -C libft
	@make -C mlx_linux
	${CC} ${CFLAGS} $^ -Llibft -Lmlx_linux -lmlx -lXext -lX11 -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	make -C libft

mlx_linux:
	make -C mlx_linux

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re mlx_linux libft
