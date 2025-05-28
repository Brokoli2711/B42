# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: elfo <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/23 11:40:01 by elfo              #+#    #+#              #
#    Updated: 2025/05/28 23:10:11 by elfo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -fPIC
AR = ar -rv
RM = rm -rf
SRC_DIR = src
OBJ_DIR = obj
INCLUDES_DIR = includes

LIBFT_DIR = libft
PRINTF_DIR = printf
GETNL_DIR = get_next_line

SRC_LIBFT = \
$(SRC_DIR)/$(LIBFT_DIR)/ft_atoi.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_bzero.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_calloc.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_isalnum.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_isalpha.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_isascii.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_isdigit.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_isprint.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_itoa.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstadd_back.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstadd_front.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstclear.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstdelone.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstiter.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstlast.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstmap.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstnew.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_lstsize.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_memchr.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_memcmp.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_memcpy.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_memmove.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_memset.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_putchar_fd.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_putendl_fd.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_putnbr_fd.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_putstr_fd.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_split.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strchr.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strdup.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_striteri.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strjoin.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strlcat.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strlcpy.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strlen.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strmapi.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strncmp.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strnstr.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strrchr.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_strtrim.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_substr.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_tolower.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_toupper.c \
$(SRC_DIR)/$(LIBFT_DIR)/ft_uitoa.c

SRC_PRINTF = \
$(SRC_DIR)/$(PRINTF_DIR)/basic_print.c \
$(SRC_DIR)/$(PRINTF_DIR)/ft_printf.c \
$(SRC_DIR)/$(PRINTF_DIR)/ft_printf_utils.c \
$(SRC_DIR)/$(PRINTF_DIR)/print_hex.c

SRC_GETNL = \
$(SRC_DIR)/$(GETNL_DIR)/free.c \
$(SRC_DIR)/$(GETNL_DIR)/get_next_line.c

SRC = $(SRC_LIBFT) $(SRC_PRINTF) $(SRC_GETNL)

OBJECTS = $(patsubst $(SRC_DIR)/$(LIBFT_DIR)/%.c, $(OBJ_DIR)/$(LIBFT_DIR)/%.o, $(SRC_LIBFT)) \
	  $(patsubst $(SRC_DIR)/$(PRINTF_DIR)/%.c, $(OBJ_DIR)/$(PRINTF_DIR)/%.o, $(SRC_PRINTF)) \
	  $(patsubst $(SRC_DIR)/$(GETNL_DIR)/%.c, $(OBJ_DIR)/$(GETNL_DIR)/%.o, $(SRC_GETNL))
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

