// Prints left-half of a hashes pyramid program given a user given number of rows.
// Headers
#include <cs50.h>  // Header for userInput functions
#include <stdio.h> // Header for i/o functions

// Main function
int main(void)
{
    // Declare variable 'height' that will store the height number
    int height;
    // Get height of pyramid from user. Only positive integers allowed (not-zero)
    do
    {
        height = get_int("Height of pyramid = ");
    }
    while (height < 1);

    // Print pyramid of users height. 3 Loops, which control every aspect of the pyramid (Height, spaces, and width)
    // Column number. Raises every time row finishes printing it's hashes
    for (int columNumber = 0; columNumber < height; columNumber++)
    {
        // First inner loop: Print one space (height - columNumber) number of times BEFORE the hashes
        for (int i = columNumber; i + 1 < height; i++)
        {
            printf(" ");
        }

        // Second inner loop: Print a hash (columNumber + 1) times AFTER the spaces
        for (int hashes = 0; hashes < columNumber + 1; hashes++)
        {
            printf("#");
        }

        // When all current row hashes are printed, print a newline and a space (for the left-side look)
        printf("\n");
    // END OF LOOP
    }
}
