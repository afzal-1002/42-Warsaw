*This project has been created as part of the 42 curriculum by mafzal.*

# push_swap

## Description

**push_swap** is a sorting algorithm project from the 42 School curriculum.  
The goal of the project is to sort a stack of integers using a limited set of allowed operations while minimizing the total number of moves.

The program receives a list of integers as input, stores them in stack **A**, and sorts them in ascending order using an auxiliary stack **B**.  
Only predefined operations such as swap, push, rotate, and reverse rotate are permitted.

This project focuses on algorithmic optimization, data structures, memory management, and strict input validation.


## Instructions

### Compilation

Compile the project using:
make clean
make fclean
make re
make


Run the program by passing integers as arguments:
./push_swap 4 67 3 87 23
You can also pass all numbers as a single string:
./push_swap "4 67 3 87 23"


To count the number of operations:
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l


### Error Handling

The program prints Error to standard error and exits if:
An argument is not a valid integer
Duplicate numbers are detected
A number exceeds INT_MAX or INT_MIN
The input is empty or invalid

Examples of invalid input:
./push_swap Hello
./push_swap --32
./push_swap "+-42"


### Algorithm Overview:
The sorting strategy depends on the input size:
2–3 elements: Direct comparisons with minimal operations
4–5 elements: Push smallest values to stack B, sort remaining elements, then push back
Larger inputs: Indexed sorting using a radix-based algorithm

Each number is first converted into an index representing its sorted position, allowing efficient comparisons during sorting.

### Resources

42 School push_swap subject
Stack-based sorting algorithms
Radix sort (bitwise approach)
Linked list manipulation in C
Integer overflow handling in C