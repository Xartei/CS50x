# Dynamic 2D Block Generator

A comprehensive command-line utility written in C that generates a custom 2D rectangular block on the terminal. It uses nested loops to dynamically construct the shape based on a user-specified character, height, and width.
## Features

By prompting the user for specific parameters, the program instantly generates the shape while handling:

   * **Custom Building Material:** Allows the user to choose any single ASCII character to compose the block.

   * **- Dynamic Dimensions:** Users define the exact height (rows) and width (columns) of the grid.

   * **- Strict Input Validation:** Ensures dimension entries are positive integers and specifically caps the maximum width at 120 characters to prevent unwanted terminal line-wrapping.

   * **- Nested Loop Construction:** Demonstrates foundational 2D grid generation by iterating horizontal character prints within a vertical row loop.

## Dependencies

   * **[CS50 Library](https://cs50.readthedocs.io/libraries/cs50/c/) `(cs50.h)`** - Used for robust and safe user input retrieval (get_char, get_int).

   * **Standard C library:** `<stdio.h>` - Used for standard output operations (printf).

## Usage

Run the compiled program in your terminal. It will sequentially prompt you for the required character and dimensions, print the resulting block, and exit.

```bash
# Compile the program (ensure the cs50 library is linked)
gcc -o block_gen block_gen.c -lcs50

# Run the program
./block_gen
```
- The program will ask for a character, height, and width.
- If invalid inputs are entered for dimensions (e.g., negative numbers or widths > 120), the program will continuously re-prompt the user until a valid integer is provided.
- Once rendered, the program prints a final message ("Do you like your block?") and gracefully terminates.