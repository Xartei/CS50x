// Prints a pyramid using hashes as block, of an users-given height
// Headers
#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Main function
int main(void)
{
    int height;
    // Get pyramids height from user. Only positive integers, MAX = 8
    do
    {
        height = get_int("Pyramid height = ");
    }
    while (height < 1 || height > 8);

    // Print a pyramid from that height
    // Outer loop
    // Controls newlines after printing the row content
    for (int rowNumber = 0; rowNumber < height; rowNumber++)
    {
        // Inner loops
        // This loop controls the printing of spaces for the left-side of the pyramid
        // (spaceNumber = height - columNumber + 1)
        for (int spaces = rowNumber; spaces + 1 < height; spaces++)
        {
            // For example, if 'height' is 5, first row get's
            // (spaceNumber = 5 - 0 + 1 = 4) spaces printed
            printf(" ");
        }

        // This loop controls the printing of left-side hashes
        // (same mechanism as right-side, separated by a space) (hashAmount = rowNumber + 1)
        for (int i = 0; i < rowNumber + 1; i++)
        {
            // For example, if 'rowNumber' is 0, first row get's (0 + 1 = 1) hashes
            printf("#");
        }

        // Print TWO spaces to separate right side from left side of pyramid
        printf("  ");

        // This loop controls the printing of right-side hashes (same mechanism as right-side,
        // separated by a space) (hashAmount = rowNumber + 1)
        for (int i = 0; i < rowNumber + 1; i++)
        {
            // For example, if 'rowNumber' is 0, first row get's (0 + 1 = 1) hashes
            printf("#");
        }

        // Print a newline after finishing printing row content. Do the full loop 'height' amount of
        // time
        printf("\n");
        // END OF LOOP
    }
}
