#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main() {
    char str1[50] = "Hello";
    char str2[] = " World";

    strcat(str1, str2);
    cout << str1 << endl;

    char str3[50] = "Hi";
    strncat(str3, " Everyone!", 5);
    cout << str3 << endl;

    char a[] = "Apple";
    char b[] = "Banana";

    int result = strcmp(a, b);
    if (result == 0)
        cout << "Strings are equal" << endl;
    else if (result < 0)
        cout << a << " comes before " << b << endl;
    else
        cout << a << " comes after " << b << endl;

    char intStr[] = "123";
    char floatStr[] = "45.67";

    int num = atoi(intStr);
    double fnum = atof(floatStr);

    cout << num << endl;
    cout << fnum << endl;

    int x = 50;
    char numStr[10];

    sprintf(numStr, "%d", x);
    cout << numStr << endl;

    return 0;
}
