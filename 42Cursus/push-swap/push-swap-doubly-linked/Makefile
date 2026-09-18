NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	push_swap.c \
	srcs/parsing/error.c \
	srcs/parsing/parse_args.c \
	srcs/stack/stack_utils.c \
	srcs/stack/stack_operations.c \
	srcs/utils/utils.c \
	srcs/sorting/array_sort.c \
	srcs/sorting/radix_sort.c 


OBJ = $(SRC:.c=.o)


all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
