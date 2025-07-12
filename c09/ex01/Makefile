LIB_NAME = libft.a
CFLAGS = -Wall -Wextra -Werror
SOURCES = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
OBJECTS = $(SOURCES:.c=.o)

all: compile archive
libft.a: compile archive 

compile: $(OBJECTS)

%.o: %.c 
	cc -c $(CFLAGS) $< -o $@

archive: 
	ar rcs $(LIB_NAME) $(OBJECTS)

clean: 
	rm -rf $(OBJECTS) ./includes/ft.h.gch

fclean: 
	rm -rf $(OBJECTS) ./includes/ft.h.gch ./libft.a

re: fclean all

