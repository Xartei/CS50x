// Custom functions prototype demo, Prototyping is useful for organization purposes, i guess they are better
// Prototype definitions are at the bottom, and main function is at the top

#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Prototypes
char selectChar(void);
int selectAmount(void);
void charPrint(char character, int amount);

// Main function
int main(void)
{
    // Initialization of amount and character variables
    char character = selectChar();
    int n = selectAmount();
    // Call print function
    charPrint(character, n);
    return 0;
}

// Prototype definitions
// selectChar: Dynamic custom function for selecting what character to print
char selectChar(void)
{
    // Ask user what character they want to Aprint
    char character = get_char("Character to print: ");
    // Return value of 'character' to main
    return character;
}

// selectAmount: Dynamic custom function for selecting how many times 'character' will be printed
int selectAmount(void)
{
    // Ask the user how many times to print the selected character. Only positive integers allowed
    int n;
    do
    {
        n = get_int("How many times? ");
    }
    while (n < 0);
    // Return value of 'n' to main
    return n;
}

// charPrint: Custom function for printing the selected character the inputed amount of times
void charPrint(char character, int amount)
{
    // Print character the amount of times requested
    for (int i = 0; i < amount; i++)
    {
        printf("%c", character);
    }
    // When function finishes, enter newline
    printf("\n");
}
