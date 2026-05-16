// Bool statements, proof that you can imitate 'true' and 'false' without including <stdio.h>
// '0' evaluates as false, any other non-zero integer evaluates as 'true'

#include <stdio.h> // Header for i/o functions

// Main function
int main(void)
{
    // The argument inside the while loop '-1' evaluates as 'true', as it is a non-zero value
    while(-1)
    {
        // Thus, this is an infinite loop, which will print infinite characters
        printf("H");
    }
    // Return 0 if successful, end of program
    return 0;
}
