NAME = push_swap

CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRC = \
	push_swap.c \
	srcs/array/array_utils.c \
	srcs/array/ft_duplicate.c \
	srcs/array/sort_int_array.c \
	srcs/libft/ft_atoi.c \
	srcs/libft/ft_is_char.c \
	srcs/libft/ft_is_space.c \
	srcs/libft/ft_free_split.c \
	srcs/libft/ft_split.c \
	srcs/libft/ft_fill_words.c \
	srcs/list/list_create.c \
	srcs/list/list_free.c \
	srcs/list/list_append.c\
	srcs/list/list_index.c \
	srcs/list/list_last.c \
	srcs/list/list_utils.c \
	srcs/list/list_size.c \
	srcs/list/list_fill.c \
	srcs/operations/push.c \
	srcs/operations/reverse.c \
	srcs/operations/rotate.c \
	srcs/operations/swap.c \
	srcs/sorting/prepare_stack.c \
	srcs/sorting/sort_three.c \
	srcs/sorting/sort_five.c \
	srcs/sorting/sort_all.c \
	srcs/sorting/is_sorted_stack.c \
	srcs/sorting/radix_sort.c \
	srcs/utils/error.c \
	srcs/utils/max_bits.c \
	srcs/utils/free_all.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
