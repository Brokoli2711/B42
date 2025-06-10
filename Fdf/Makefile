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
	${CC} ${CFLAGS} -Ilibft -I./mlx_linux -I$(INC_DIR) -c $< -o $@

${NAME}: ${OBJECTS} Makefile libft
	@make -C libft
	@make -C mlx_linux
	${CC} ${CFLAGS} ${OBJECTS} -Llibft -lft -Lmlx_linux -lmlx_Linux -lm -lXext -lX11 -lz -o ${NAME}

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
	make fclean -C libft
	${RM} ${NAME}

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re mlx_linux libft
