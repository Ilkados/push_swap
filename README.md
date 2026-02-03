Based on the sources provided and the specific constraints from the **Subject PDF** and our conversation regarding the **Turk Algorithm** and **Linked Lists**, here is a complete `README.md` template for your project.

***

# Push_swap

*This project has been created as part of the 42 curriculum by <your_login>.*

## Description

**Push_swap** is a highly structured algorithmic project at 42 School. The goal is to sort a stack of random integers (Stack A) in ascending order using a second auxiliary stack (Stack B) and a specific set of instructions.

The core challenge is not just to sort the numbers, but to do so with the **lowest possible number of operations**. The project focuses on algorithmic complexity (Big O), data structure manipulation, and sorting optimization.

For this implementation, I utilized the **Turk Algorithm** combined with a **Circular Doubly Linked List**, achieving the target benchmarks (e.g., sorting 500 numbers in fewer than 5500 operations).

## Technical Choices

*   **Algorithm:** **The Turk Algorithm**. This strategy pushes elements from Stack A to Stack B in a descending pre-sorted order by calculating the "cheapest" node to move (based on rotation costs). It then pushes them back to A in the correct position.
*   **Data Structure:** **Circular Doubly Linked Lists**. This allows efficient traversal in both directions (next/prev) and makes rotation operations (`ra`, `rra`) O(1) constant time by simply updating the head pointer.
*   **Preprocessing:** **Indexing/Ranking**. Input values are converted to their relative rank (0 to N-1) to simplify comparisons and ignore value magnitude.

## The Operations

The allowed operations to manipulate the stacks are:

| Code | Instruction | Action |
| :--- | :--- | :--- |
| `sa` | swap a | Swap the first 2 elements at the top of stack A. |
| `sb` | swap b | Swap the first 2 elements at the top of stack B. |
| `ss` | swap a + b | `sa` and `sb` at the same time. |
| `pa` | push a | Take the first element at the top of B and put it at the top of A. |
| `pb` | push b | Take the first element at the top of A and put it at the top of B. |
| `ra` | rotate a | Shift all elements of stack A up by 1. The first element becomes the last. |
| `rb` | rotate b | Shift all elements of stack B up by 1. The first element becomes the last. |
| `rr` | rotate a + b | `ra` and `rb` at the same time. |
| `rra` | reverse rotate a | Shift all elements of stack A down by 1. The last element becomes the first. |
| `rrb` | reverse rotate b | Shift all elements of stack B down by 1. The last element becomes the first. |
| `rrr` | reverse rotate a + b | `rra` and `rrb` at the same time. |

## Instructions

### Compilation
Use the `Makefile` to compile the project. The executable will be named `push_swap`.

```bash
make
```

### Execution
Run the program with a list of integers as arguments.

```bash
./push_swap 2 1 3 6 5 8
```

You can also pass numbers as a single string:

```bash
./push_swap "2 1 3 6 5 8"
```

### Verification (Checker)
To check if the sorting instructions are valid and the stack is sorted, pipe the output to the provided `checker_OS` (or your own bonus checker).

```bash
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
```
*Expected Output:* `OK`

### Error Handling
The program prints "Error" to standard error if:
*   Arguments contain non-numeric characters.
*   Arguments contain duplicates.
*   Arguments exceed integer limits (`INT_MAX` / `INT_MIN`).

## Resources

This project relied on the following references for algorithmic logic and C implementation details:

*   **Algorithms & Logic:**
    *   *Grokking Algorithms* by Aditya Bhargava - For understanding Big O notation and Divide & Conquer strategies.
    *   "Mastering the Turk Algorithm for Push_swap" by A. Yigit Ogun - The primary logic source for the cost calculation and sorting strategy.
    *   "Push_swap: an Efficient Positional Sorting Algorithm" by Mia Combeau (codequoi) - For understanding the project constraints and parsing logic.

*   **Video Tutorials:**
    *   "Push_swap: a performant sorting algorithm using 2 stacks" by Oceano - For visualization of linked list manipulations.
    *   "Push_swap TUTORIAL!" by Thuggonaut - For step-by-step implementation details.

### AI Usage
AI tools were used in this project to assist with:
*   **Conceptualization:** Explaining the difference between array-based stacks vs. linked list stacks and visualising the "rotation" mechanism in memory.
*   **Module Structure:** Helping design the header file structure (`push_swap.h`) to properly link the struct definitions with the operation functions.
*   **Logic Verification:** Clarifying the math behind the "cheapest move" calculation in the Turk algorithm (calculating simultaneous rotations `rr` vs individual rotations `ra`/`rb`).