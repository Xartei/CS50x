// Become familiar wih C syntax
// Learn to debug buggy code

// Error: <stdio.h> not included while calling printf()
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // General error: not finishing lines with ';'
    
    // Ask for your name and where live
    // Error: variable not declared before initialization (no data type)
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");

    // Say hello
    // Error: function 'printf()' mistakenly called as 'print()'
    // Error: user format code for integers (%i) when calling string (%s)
    // Mistake: not including \n for newline (minus style)
    printf("Hello, %s, from %s!\n", name, location);

    return 0;
}
