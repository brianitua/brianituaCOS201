#include <iostream>
using namespace std;
int main() {
    int a = 5;
    cout << "Initial value of a: " << a << endl;

    cout << "Post-increment a++: " << a++ << endl; 
    cout << "Value of a after post-increment: " << a << endl;

    cout << "Pre-increment ++a: " << ++a << endl;
    cout << "Value of a after pre-increment: " << a << endl;

    cout << "Post-decrement a--: " << a-- << endl;
    cout << "Value of a after post-decrement: " << a << endl;

    cout << "Pre-decrement --a: " << --a << endl;
    cout << "Value of a after pre-decrement: " << a << endl;

    return 0;
}