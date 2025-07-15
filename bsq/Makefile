NAME = out
CC = cc
ARGS = -Wall -Wextra -Werror
SRCS = $(wildcard *.c)
OBJS = $(SRCS: .c=.o)

$(NAME) : $(OBJS)
	$(CC) $(ARGS) -o $(NAME) $(OBJS)

all: $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
