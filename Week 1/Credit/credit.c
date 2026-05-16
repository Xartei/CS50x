// Credit card validity checker
// timeSpentHere = (7.5) hours || This is the code I uploaded originally
// I guess i'll refactor it, tomorrow
// Headers
#include <cs50.h>  // Header for userPrompt functions
#include <stdio.h> // Header for i/o functions

// Prototypes
int cardDigit(long long card);
int luhnAlgo(long long card, int dNum);
int cardType(long long card, int dNum);

// Main function
int main(void)
{
    // Get credit card number, only positive integers allowed
    long long card = get_long_long("Number: ");

    // Check card validity. (Triple check: digit, Luhn's algo and card type)
    int dNum = cardDigit(card);
    // If card digit returned -1 because digit number is INVALID
    if (dNum != 13 && dNum != 15 && dNum != 16)
    {
        // End of program, return 0 if successful
        return 0;
    }

    int lAlgoCheck = luhnAlgo(card, dNum);
    // If luhnAlgo returned -1 because card did not pass algo
    if (lAlgoCheck != 0)
    {
        // End of program, return 0 if successful
        return 0;
    }

    int cTypeCheck = cardType(card, dNum);
    // If cardType returner -1 because card did not pass algo
    if (cTypeCheck != 0)
    {
        return 0;
    }
    else
    {
        // End of program, return 0 if successful
        return 0;
    }
}

// Prototype defs
// Get credit card digit amount
int cardDigit(long long card)
{
    // Define a variable to store digit-number, and one for division counter
    int dNum = 1;
    long long div = 10;
    // Get digit amount
    while (card / div > 0)
    {
        // If card / div > 0, keep dividing by powers of 10, and add 1 to digit counter
        // Repeat until card / div < 0 (strip the decimal part with int)
        dNum++;
        div *= 10;
    }
    switch (dNum)
    {
        // If the card digit number matches with any of the cards digit number conventions
        // (13, 15 or 16) then return dNum to main
        case 13:
        case 15:
        case 16:
            return dNum;
            break;
        default:
            // If not, print "INVALID" and return
            printf("INVALID\n");
            return -1;
            break;
    }
}

// Check if card number passes Luhn's algorithm test
int luhnAlgo(long long card, int dNum)
{
    // Open a loop in which you get every other number from second-to-last with modulo and divisions
    // 'div' is one order of magnitude below 'mod' (e.g., mod = 100 && div = 10)
    // Formula = (num mod 'mod') / div (e.g., (5432 mod 1000) / 100 = 4.32, int 4)
    long long mod = 100;
    long long div = 10;
    int luhnSum = 0;

    for (int i = 0; i < dNum; i += 2)
    {
        // Get every other number after second-to-last digit and multiply that number by 2
        int otNum = (card % mod) / div;
        otNum *= 2;
        // If number has 2 digits
        if (otNum > 9)
        {
            // Separate both digits using the mod-div loop
            // Get last digit and add it to luhnSum
            int halfDigit = otNum % 10;
            luhnSum += halfDigit;

            // Get second-to-last digit (no need to create variable loops because maximum 2 digit
            // number is 81) Add it to luhnSum
            halfDigit = (otNum % 100) / 10;
            luhnSum += halfDigit;
        }
        // If number has 1 digit
        else
        {
            // Inmediately add to luhnSum variable
            luhnSum += otNum;
        }
        // Continue to next digit and repeat until every other number is added up
        mod *= 100;
        div *= 100;
    }

    // Open a loop in which you get every other number from last with modulo and divisions
    // Reset mod and div (configured to get every other number from last)
    mod = 10;
    div = 1;
    for (int i = 0; i < dNum; i += 2)
    {
        // Get every other number after last digit
        int otNum = (card % mod) / div;
        // Inmediately add to luhnSum variable
        luhnSum += otNum;
        // Continue to next digit and repeat until every other number is added up
        mod *= 100;
        div *= 100;
    }

    // If luhnSum mod 10 != 0, print INVALID, if not, continue to get card type
    if (luhnSum % 10 != 0)
    {
        // Print "INVALID" and return -1.
        printf("INVALID\n");
        return 1;
    }
    return 0;
}

int cardType(long long card, int dNum)
{
    // mod:div ratio has to be 100:1 to get the first 2 numbers
    long long mod = 100;
    long long div = 1;
    // Multiply mod and div by 10 'digit number - 2' of times (because mod starts at 100)
    for (int i = 0; i < dNum - 2; i++)
    {
        mod *= 10;
        div *= 10;
    }
    // Check the first two digits of the card using mod-div (and declare visaCheck globally)
    int firstDigits = (card % mod) / div;
    int visaCheck;

    // Card type checker based on first two digits convention
    // 16-digit cards (VISA, MASTERCARD)
    if (dNum == 16)
    {
        // MASTERCARD first digits == 51, 52, 53, 54, 55
        switch (firstDigits)
        {
            case 51:
            case 52:
            case 53:
            case 54:
            case 55:
                // If card passed all checks and has MASTERCARD first digits, print MASTERCARD and
                // return 0 (successful)
                printf("MASTERCARD\n");
                return 0;
                break;
            // If not, check with VISA
            default:
                break;
        }
        // VISA first digits == 4
        // We have to get the first digit from firstDigit variable and check if it is 4
        visaCheck = (firstDigits % 100) / 10;
        // If the digit IS indeed 4
        if (visaCheck == 4)
        {
            // Print VISA and return 0 (successful)
            printf("VISA\n");
            return 0;
        }
        // If the digit is any other than 4
        else
        {
            // Print "INVALID" and return 1 (ok length, no compatible firstDigits)
            printf("INVALID\n");
            return 1;
        }
    }
    // 15-digit cards (AMEX)
    else if (dNum == 15)
    {
        // AMEX first digits == 34, 37
        switch (firstDigits)
        {
            case 34:
            case 37:
                // If card passed all checks and has AMEX first digits, print AMEX and return 0
                // (successful)
                printf("AMEX\n");
                return 0;
                break;
            // If not, print INVALID and return 1 (ok length, no compatible firstDigits)
            default:
                printf("INVALID\n");
                return 1;
                break;
        }
    }
    // 13-digit cards (VISA)
    else if (dNum == 13)
    {
        // VISA first digits == 4
        // We have to get the first digit from firstDigit variable and check if it is 4
        visaCheck = (firstDigits % 100) / 10;
        // If the digit IS indeed 4
        if (visaCheck == 4)
        {
            // Print VISA and return 0 (successful)
            printf("VISA\n");
            return 0;
        }
        // There are no more remaining possibilities, print INVALID and return 2 (edge-case)
        else
        {
            printf("INVALID\n");
            return 2;
        }
    }
    // Return 0 if successful
    return 0;
}
