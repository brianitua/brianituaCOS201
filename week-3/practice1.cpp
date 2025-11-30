#include <iostream>
using namespace std;

int main() {
    int number;
    cout<<"Hello, input a number: ";
    cin >> number;
    if (number % 5 == 0) {
        std::cout << "The number " << number << " is a multiple of 5." << std::endl;
    } 
    if (number % 2 == 0) {
        std::cout << "\nThe number " << number << " is even." << std::endl;
    } 
    else {
        std::cout << "The number " << number << " is odd." << std::endl;
    }

}