// Calculate your half of a restaurant bill
// Data types, operations, type casting, return value

#include <cs50.h>
#include <stdio.h>

float half(float bill, float tax, int tip);

int main(void)
{
    float bill_amount = get_float("Bill before tax and tip: ");
    float tax_percent = get_float("Sale Tax Percent: ");
    int tip_percent = get_int("Tip percent: ");

    // (I didn't know you could pass a function return value as an argument!)
    printf("You will owe $%.2f each!\n", half(bill_amount, tax_percent, tip_percent));

    return 0;
}

// TODO: Complete the function
float half(float bill, float tax, int tip)
{
    // Convert tax and tip into aritmethically usable, div / 100.0 (.0 to ensure float)
    float dTax = tax / 100.0;
    float dTip = tip / 100.0;

    // Multiply 'bill' by 'dTax' and add results to 'bill' to get post-tax bill
    float taxBill = (bill + (bill * dTax));
    // Because exercise specifies that tip is calculated with post-tax bill
    // Multiply 'taxBill' by 'dTip' and add the results to 'taxBill'
    // Divide the results by '2' to get final splitted bill amount
    float finalBill = (taxBill + (taxBill * dTip)) / 2;

    // Return finalBill from main to print if successful, end of function
    return finalBill;
}
