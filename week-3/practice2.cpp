#include <iostream>
using namespace std;

int main() {
    int age;

    cout<<"Input your age: ";
    cin>>age;

    if (age<18) {
        cout<<"Hey yo, you're a baby";
    }
    else if (age>18) {
        cout<<"Hi boss, you're an adult";
    }
    else {
        cout<<"Gerrout, you're not supposed to be here";
    }
}