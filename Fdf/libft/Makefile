# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:40:01 by elfo              #+#    #+#              #
#    Updated: 2025/03/25 11:19:42 by egelma-b         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar -rv
RM = rm -rf
SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes

LIBFT_DIR = libft
PRINTF_DIR = printf
GETNL_DIR = get_next_line

SRC = $(wildcard $(SRC_DIR)/$(LIBFT_DIR)/*.c) $(wildcard $(SRC_DIR)/$(PRINTF_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/$(LIBFT_DIR)/%.c, $(OBJ_DIR)/$(LIBFT_DIR)/%.o, $(wildcard $(SRC_DIR)/$(LIBFT_DIR)/*.c)) \
	$(patsubst $(SRC_DIR)/$(PRINTF_DIR)/%.c, $(OBJ_DIR)/$(PRINTF_DIR)/%.o, $(wildcard $(SRC_DIR)/$(PRINTF_DIR)/*.c)) \
	$(patsubst $(SRC_DIR)/$(GETNL_DIR)/%.c, $(OBJ_DIR)/$(GETNL_DIR)/%.o, $(wildcard $(SRC_DIR)/$(GETNL_DIR)/*.c))
DEPS = $(OBJECTS:.o=.d)

all: $(NAME)

# Crear objetos
$(OBJ_DIR)/$(LIBFT_DIR)/%.o: $(SRC_DIR)/$(LIBFT_DIR)/%.c | $(OBJ_DIR)/$(LIBFT_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR)/$(PRINTF_DIR)/%.o: $(SRC_DIR)/$(PRINTF_DIR)/%.c | $(OBJ_DIR)/$(PRINTF_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDES_DIR)

$(OBJ_DIR)/$(GETNL_DIR)/%.o: $(SRC_DIR)/$(GETNL_DIR)/%.c | $(OBJ_DIR)/$(GETNL_DIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@ -I $(INCLUDES_DIR)


# Crear directorios
$(OBJ_DIR)/$(LIBFT_DIR):
	mkdir -p $(OBJ_DIR)/$(LIBFT_DIR)

$(OBJ_DIR)/$(PRINTF_DIR):
	mkdir -p $(OBJ_DIR)/$(PRINTF_DIR)

$(OBJ_DIR)/$(GETNL_DIR):
	mkdir -p $(OBJ_DIR)/$(GETNL_DIR)


# Crear libft.a
$(NAME): $(OBJECTS) Makefile
	$(AR) $(NAME) $(OBJECTS)

clean :
	$(RM) $(OBJ_DIR)

fclean : clean
	$(RM) $(NAME)

re: fclean all

# Incluir dependencias
-include $(DEPS)

.PHONY: all clean fclean re

