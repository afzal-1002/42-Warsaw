NAME = main

CPP = c++
CPPFLAGS = -Wall -Wextra -Werror -g3 -std=c++98
LDFLAGS =

SRCS = main.cpp FileHandler.cpp
OBJS = $(SRCS:.cpp=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.cpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) file.replace

re: fclean all

.PHONY: all clean fclean re