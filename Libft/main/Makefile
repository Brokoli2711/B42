NAME = main.c
BNAME = bmain.c
LIB = libft.a
CC = gcc -Wall -Wextra -Werror
OBJECT = correction
LIBPATH = ../
TAGL = -L
TAGO = -o

all: $(NAME)
	$(CC) $(NAME) -L. $(LIBPATH)$(LIB) -o $(OBJECT)

bonus: $(BNAME)
	$(CC) $(BNAME) -L. $(LIBPATH)$(LIB) -o $(OBJECT)

clean:
	rm -rf $(OBJECT)

re: clean all
