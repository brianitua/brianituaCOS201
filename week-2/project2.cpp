#include <iostream>
int main() {
    int a, b, temp;

    std::cout << "Enter first integer (a): ";
    std::cin >> a;
    std::cout << "Enter second integer (b): ";
    std::cin >> b;

    std::cout << "Before swapping: a = " << a << ", b = " << b << std::endl;

    temp = a;
    a = b;
    b = temp;

    // Display values after swapping
    std::cout << "After swapping: a = " << a << ", b = " << b << std::endl;

    return 0;
}