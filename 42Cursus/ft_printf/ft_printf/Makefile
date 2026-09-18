NAME = libftprintf.a
CC = gcc

CFLAGS 	= -Wall -Wextra -Werror
SRCS 	= 	src/ft_printf_helper.c \
			src/ft_printf.c \
			src/ft_putchr.c \
			src/ft_putnbr.c \
			src/ft_putptr.c \
			src/ft_putstr.c \
			src/ft_specifiers.c \

RM		=	rm -f

OBJS = $(SRCS:.c=.o)

all		:	$(NAME)

$(NAME): $(OBJS)
	@ ar rcs $(NAME) $(OBJS)

%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@

#gcc -Wall -Wextra -Werror main.c -L. -lftprintf -o test_program

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
