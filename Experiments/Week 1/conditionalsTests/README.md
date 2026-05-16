# Interactive Y/N Confirmation Prompt

<img width="1428" height="296" alt="agreeGif" src="https://github.com/user-attachments/assets/9b25b2ed-ef10-4676-8bd8-5b6aab48b164" />

A concise command-line utility written in C that prompts the user for a single-character Yes or No confirmation. It utilizes a continuous loop to enforce strict input validation until a valid response is received.
## Features

By leveraging conditional statements and an infinite loop, the program effectively handles user input by providing:

   * **Case-Insensitive Checking:** Accepts both uppercase and lowercase inputs (Y/y or N/n) for maximum user convenience.

   * **Strict Input Validation:** Utilizes a while(true) loop to trap the user in the prompt cycle until a valid confirmation character is provided.

  * **Graceful Error Handling:** Provides immediate, clear feedback ("Only Y/N allowed") if an unrecognized character or symbol is entered, and automatically re-prompts the question.

  * **Character-Based Control Flow:** Demonstrates fundamental conditional logic (if, else if, else) and loop control (break, continue) evaluating single char data types.

Dependencies

   * **CS50 Library `(cs50.h)`** - Used for safely retrieving a single character from the user (get_char).

   * **Standard C library: <stdio.h>** - Used for standard console output (printf).

Usage

Run the compiled program in your terminal. It will prompt you for an agreement confirmation, evaluate your response, and either exit or ask again.

```bash
# Compile the program (ensure the cs50 library is linked)
gcc -o yn_prompt yn_prompt.c -lcs50

# Run the program
./yn_prompt
```

 The program will ask: Do you agree? (Y/N):

- If you input `Y` or `y`, it prints "OK, agreed." and terminates.
- If you input `N` or `n`, it prints "OK, Disagreed" and terminates.
   - If you input anything else, it notifies you that it is not case-sensitive and only accepts Y/N, then instantly asks the original question again.
