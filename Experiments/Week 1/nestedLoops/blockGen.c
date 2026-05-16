// Create a 2D block generator using nested loops. Dynamic character and block-size selection

#include <cs50.h> // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Prototypes
char charSelect(void);
int heightSelect(void);
int widthSelect(void);
void printBlock(char character, int height, int width);

// Main Function
int main(void)
{
    // Initialize character, height and width into main
    char character = charSelect();
    int height = heightSelect();
    int width = widthSelect();
    // Print the block on the terminal. Use a nested loop (One for height, one for width)
    printBlock(character, height, width);
    // Return 0 if successful, end of program
    return 0;
}

// Prototype defs
// Ask user which character the block must consist of. Function must return a char (character). Doesn´t take arguments
char charSelect(void)
{
    char character = get_char("Character the block must be composed of: ");
    return character;
}
// Ask user height of the block. Function must return an int (height). Doesn´t take arguments
int heightSelect(void)
{
    // Declare variable 'height' inside the function
    int height;
    // Only positive integers allowed
    do
    {
        height = get_int("Height of block: ");
    }
    while (height < 0);
    // Return variable 'height' to main
    return height;
}

// Ask user width of the block. Function must return an int (width). Doesn´t take arguments
int widthSelect(void)
{
    // Declare variable 'width' inside the function
    int width;
    // Only positive integers allowed. Max width: 125
    do
    {
        width = get_int("Width of block (MAX: 120): ");
    }
    while (width < 0 || 120 < width);
    // Return variable 'width' to main
    return width;
}

// Print block on the terminal. Take character, height and width values prompted from the user into main
void printBlock(char character, int height, int width)
{
    // Insert newline every time block reaches width requested per row, the amount of times prompted (height)
    for (int hc = 0; hc < height; hc++)
    {
        // Block prints requested number of characters horizontally first (width)
        for (int wc = 0; wc < width; wc++)
        {
            printf("%c", character);
        }
        printf("\n");
    }
    printf("Do you like your block?\n");
}
