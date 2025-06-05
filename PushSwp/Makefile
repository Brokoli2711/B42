NAME = push_swap
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -MMD -MP -g

SRC = $(SRC_DIR)/errors.c $(SRC_DIR)/find_nodes.c $(SRC_DIR)/init_nodes.c $(SRC_DIR)/init_stack.c \
	$(SRC_DIR)/push_operation.c $(SRC_DIR)/push_swap.c $(SRC_DIR)/push_swap_utils.c \
	$(SRC_DIR)/reverse_rotate_operation.c $(SRC_DIR)/rotate_operation.c $(SRC_DIR)/sort.c \
	$(SRC_DIR)/sort_utils.c $(SRC_DIR)/split.c $(SRC_DIR)/swap_operation.c
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC))
DEPS = $(OBJECTS:.o=.d)

all: ${NAME}

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	${CC} ${CFLAGS} -Ilibft -c $< -o $@ -I $(INC_DIR)

${NAME}: ${OBJECTS}
	@make -C libft
	${CC} ${CFLAGS} -Llibft ${OBJECTS} -lft -o ${NAME}

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

libft:
	make -C libft

clean:
	make clean -C libft
	${RM} ${OBJ_DIR}

fclean: clean
	${RM} ${NAME}

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re libft
