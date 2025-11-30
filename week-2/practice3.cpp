#include <iostream>
using namespace std;
int main() {
    double f;
    cout << "Hello user, enter temperature in fahrenheit: ";
    cin >> f;
    double c = (f - 32) * 5 / 9;
    cout << "The temperature in celsius is: " << c << endl;

    double fnew = (c * 9 / 5) + 32;
    cout << "The temperature in fahrenheit is: " << fnew << endl;
    return 0;
}