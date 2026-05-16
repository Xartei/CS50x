// Y/N Program -- This only works with chars, not strings

#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Main function
int main(void)
{
    // Infinite loop for handling edge cases (e.g. answer is different to Y/N)
    while (true)
    {
        // Ask user for confirmation, then check answer (only Y/N allowed)
        char answer = get_char("Do you agree? (Y/N): ");
        // If answer is Y, say "agree" and exit
        if (answer == 'Y' || answer == 'y')
        {
            printf("OK, agreed.\n");
            break;
        }
        // If answer is 'N', say "disagree" and exit
        else if (answer == 'N' || answer == 'n')
        {
            printf("OK, Disagreed\n");
            break;
        }
        // If answer is different to Y/N, clarify, and re-prompt question
        else
        {
            printf("(Only Y/N allowed -- no case sensitive)\n");
            continue;
        }
    }
    // Return 0 if successful, end of program
    return 0;
}
