#include <iostream>
using namespace std;

int main() {
    int n = 7;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {

            if (
                j == 0 && i != 0 ||               
                j == n && i != 0 ||               
                i == 0 && j != 0 && j != n ||     
                i == n / 2                         
            )
                cout << "*";
            else
                cout << " ";
        }
        cout << endl;
    }

    return 0;
}