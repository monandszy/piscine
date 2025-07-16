NAME = bsq
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)

$(NAME):
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

.PHONY: clean fclean
