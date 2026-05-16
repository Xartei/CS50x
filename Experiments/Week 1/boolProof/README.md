# Boolean Logic Demonstrator

<img width="1428" height="296" alt="boolGif" src="https://github.com/user-attachments/assets/5ce55f33-f970-497d-8576-685ad5e95a8f" />

A concise command-line program written in C that demonstrates how integer values are evaluated as boolean conditional statements, proving that any non-zero integer (such as `-1`) acts as true without needing the `<stdbool.h>` library.
## Features

By leveraging C's native conditional evaluation, the program instantly demonstrates:

   * **Truth Evaluation:** Proves that `-1` (or any non-zero value) evaluates to true inside a while loop condition.

    * **Infinite Looping:** Implements a deliberate, unending cycle relying entirely on integer-based logic.

   * **Continuous Output:** Floods the standard output with the character `H` at high speed.

## Dependencies

   - **Standard C library:** `<stdio.h>` - Used for basic input/output operations (printf).

## Usage

Run the compiled program in your terminal. It will immediately execute the loop and continuously print to the console.

```bash
# Compile the program
gcc -o bool_demo bool_demo.c

# Run the program
./bool_demo
```
- The program will output an infinite stream of the character "H" to your terminal.
    - The loop runs indefinitely since the condition -1 never changes to 0 (false).
      - **To exit: Press ctrl+c to forcefully kill the program.**
