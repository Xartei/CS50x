# Modular Character Repeater

<img width="1428" height="296" alt="protoCstmFuncGif" src="https://github.com/user-attachments/assets/7aa7f4d7-50b2-49d5-b9dc-263ea29ef1ca" />

A concise command-line utility written in `C` that repeats a user-specified character a designated number of times. It serves as a practical demonstration of `C` function prototyping, modular program design, and top-down code organization.
## Features

By separating specific tasks into distinct, reusable functions, the program demonstrates:

   * **Function Prototyping:** Declares functions at the top of the file so the main function can remain the first block of code, greatly improving readability and organization.

   * **Modular Architecture:** Breaks the program down into three dedicated functions: one for character input, one for amount input, and one for execution/printing.

   * **Input Validation:** Utilizes a do-while loop within the selectAmount function to strictly enforce that the repetition count is a positive integer.

   * **Dynamic Iteration:** Passes prompted variables as arguments into the print function, utilizing a for loop to output the character horizontally.

## Dependencies

  * **CS50 Library `(cs50.h)`** - Used for safely retrieving characters and integers from the user (get_char, get_int).

  * **Standard C library:** `<stdio.h>` - Used for standard console output operations (printf).

## Usage

Run the compiled program in your terminal. It will prompt you for a character, ask how many times to print it, output the result, and terminate.

```bash
# Compile the program (ensure the cs50 library is linked)
gcc -o char_repeater char_repeater.c -lcs50

# Run the program
./char_repeater
```
- The program will first ask: Character to print:
- It will then ask: How many times?
- If a negative number is entered for the amount, it will trap the user in a loop and continuously re-prompt until a valid positive integer is provided.
- The chosen character is printed in a single horizontal line followed by a newline, after which the program exits.
