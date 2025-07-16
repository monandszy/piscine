SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = ft_cat

all: 
	cc -Wall -Wextra -Werror $(SRCS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)
