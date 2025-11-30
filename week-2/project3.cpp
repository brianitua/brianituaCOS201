#include <iostream>

//Ask the user for the total purchase amount and calculate the sales tax at 6%
int main() {
    double purchaseAmount, salesTax;

    // Get the total purchase amount from the user
    std::cout << "Enter the total purchase amount: ";
    std::cin >> purchaseAmount;

    // Calculate the sales tax
    salesTax = purchaseAmount * 0.06;

    // Display the sales tax
    std::cout << "Sales tax (6%): " << salesTax << std::endl;

    return 0;
}