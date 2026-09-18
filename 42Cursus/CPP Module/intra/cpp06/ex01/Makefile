NAME = Serialization
CPP = c++ 
CPPFLAGS = -g3 -Wall -Werror -Wextra -std=c++98

SRCS = main.cpp Serializer.cpp
OBJS = $(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) $(OBJS) -o $(NAME)
	@echo " Project compiled $(NAME) successfully"

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re