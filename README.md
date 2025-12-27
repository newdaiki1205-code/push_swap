# Push_swap
This project has been created as part of the 42 curriculum by dshirais.

## Description
Push_swap is a highly efficient C project that solves a logic puzzle: sorting a stack of integers using two stacks (Stack A and Stack B) and a limited set of operations. 
The goal is to sort the data in Stack A in ascending order with the minimum number of instructions.
This implementation focuses on algorithmic efficiency by using **Coordinate Compression (Ranking)** and a **Bitwise Radix Sort algorithm** to handle large datasets (up to 500+ numbers) within the strict operation limits of the 42 curriculum.

### Features
**Robust Parsing**: Handles edge cases such as non-numeric input, integer overflows (using long for safe checks), and duplicate values.
**Data Normalization**: Converts raw integers into ranks ($0$ to $N-1$) to simplify the sorting process and enable bitwise operations.
**Optimized Radix Sort**: Uses bitwise manipulation to sort large stacks in $O(N \log N)$ time complexity.
**Custom Linked List Stack**: A custom implementation of a stack structure tailored for the required push, swap, and rotate operations.

## Instructions
### Compilation
The project includes a Makefile that compiles the source files into the push_swap executable.
```
make
```

### Execution
Run the program by providing a list of integers as arguments:
```
./push_swap 3 2 5 1 4
```

To count the number of operations, you can pipe the output to wc:
```
./push_swap 3 2 5 1 4 | wc -l
```

### Clean up
```
make fclean
```

## Resources
Algorithms: learned through *Algorithms in C by Robert Sedgewick (1990)*

AI Usage
During this project, I used Gemini (AI) as a thought partner for the architecture planning; discussing the efficiency of $O(N \log N)$ vs $O(N^2)$ approaches for the initial error checking and ranking.