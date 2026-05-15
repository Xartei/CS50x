// Greedy algorithm to calculate minimum amount of coint to give a certain change
// Coin denominations = 25, 10, 5, 1
// Headers
#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Main function
int main(void)
{
    // First, prompt the user to give you amount of change owed
    // Change must be bigger than zero
    int change;
    do
    {
        change = get_int("Change owed: ");
    }
    while (change < 0);

    // Calculate amount of quarters (25) owed and update change remanining
    // Amount of quarters = change/25 (e.g., 50 / 25 = 2 quarters needed)
    int qamnt = change / 25;
    change %= 25;

    // Calculate amount of dimes (10) owed and update change remaining
    // Amount of dimes = change/10 (e.g., 30 / 10 = 3 dimes needed)
    int damnt = change / 10;
    change %= 10;

    // Calculate amount of nickels (5) owed and update change remaining
    // Amount of nickels = change/5 (e.g., 20 / 5 = 4 nickels)
    int namnt = change / 5;
    change %= 5;

    // Calculate amount of pennies (1) owed
    // Amount of pennies = change/1 (e.g., 5 / 1 = 5 pennies used)
    int pamnt = change / 1;
    change %= 1;

    // Print amount of coins used
    printf("%i\n", qamnt + damnt + namnt + pamnt);
}
