NAME = push_swap
SRC_DIR = src
OBJ_DIR = obj
INC_DIR = includes

CC = gcc
RM = rm -rf

CFLAGS = -Wall -Wextra -Werror -MMD -MP

SRC = $(wildcard $(SRC_DIR)/*.c)
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
	${RM} ${OBJECTS} ${DEPS}

fclean: clean
	${RM} ${NAME}

-include $(DEPS)

re: fclean all

.PHONY: all clean fclean re libft
