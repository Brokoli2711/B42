NAME = fdf
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -MMD -MP

SRC = $(SRC_DIR)/draw.c $(SRC_DIR)/fdf.c $(SRC_DIR)/hooks.c $(SRC_DIR)/limits.c \
      $(SRC_DIR)/points.c $(SRC_DIR)/start.c $(SRC_DIR)/map.c $(SRC_DIR)/scale.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(OBJECTS:.o=.d)

$(info SRC = $(SRC))
$(info OBJECTS = $(OBJECTS))

all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -Ilibft -I./mlx_linux -c $< -o $@ -I $(INC_DIR)

${NAME}: ${OBJECTS}
	@make -C libft
	@make -C mlx_linux
	${CC} ${CFLAGS} ${OBJECTS} -Llibft -lft -L/usr/lib -Lmlx_linux -lmlx_Linux -Imlx_linux -lm -lXext -lX11 -lz -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	make -C libft

mlx_linux:
	make -C mlx_linux

clean:
	make clean -C libft
	make clean -C mlx_linux
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re mlx_linux libft
