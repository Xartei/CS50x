// "Hello, [name]" program

#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// main function
int main(void)
{
    // prompt the user for their name, then print it
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
    // return 0 if successful, end of program
    return 0;
}
