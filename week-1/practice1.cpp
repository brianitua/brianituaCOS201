#include <iostream>

using namespace std;

int main()
{
    string name;
    cout << "Hello user, enter your name: ";
    cin >> name;
    cout << "Hello World!" << endl << "My name is " << name << endl;

    cout << "I am learning C++ programming language." << endl;

    int x = 2;
    int y = 3;
    int sum = x + y;
    cout << "The sum of " << x << " and " << y << " is: " << sum << endl;
    return 0;
}