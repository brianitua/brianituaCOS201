#include <iostream>
using namespace std;

int addition (int num1, int num2) {
    int result;
    result = num1 + num2;
    return result;
}

int subtraction (int num1, int num2) {
    int result;
    result = num1 - num2;
    return result;
}

int multiplication (int num1, int num2) {
    int result;
    result = num1 * num2;
    return result;
}

int division (int num1, int num2) {
    int result;
    result = num1 / num2;
    return result;
}

int  Modulus (int num1, int num2) {
    int result;
    result = num1 % num2;
    return result;
}

int main (){
    int num1;
    int num2;
    cout<<"Enter the first number ";
    cin >> num1;
    cout<<"Enter the second number ";
    cin >> num2;
    int addition1 = addition(num1, num2);
    int subtraction1 = subtraction(num1, num2);
    int multiplication1 = multiplication(num1, num2);
    int division1 = division(num1, num2);
    int Modulus1 = Modulus(num1, num2);
    
    cout << "Find below your outputs\n";
    cout << "The addition is " << addition1 << endl;
    cout << "The subtraction is " << subtraction1 << endl;
    cout << "The multiplication is " << multiplication1 << endl;
    cout << "The division is " << division1 << endl;
    cout << "The modulus is " << Modulus1 << endl;
}