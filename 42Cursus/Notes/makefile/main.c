/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mafzal < mafzal@student.42warsaw.pl>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 20:51:30 by mafzal            #+#    #+#             */
/*   Updated: 2024/12/02 22:17:10 by mafzal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# Compiler and flags
CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

# Source and object files
SRC     = main.c file1.c file2.c
OBJ     = $(SRC:.c=.o)

# Output file name
NAME    = program

# Default rule: build the program
all: $(NAME)

# Rule to create the final executable
$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

# Rule to compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up object files
clean:
	rm -f $(OBJ)

# Clean up object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all
