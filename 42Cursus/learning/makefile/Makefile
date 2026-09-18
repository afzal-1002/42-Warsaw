NAME=program
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
RM = rm -rf
AR = ar -crs

SRC = main.c hello.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
