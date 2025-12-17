#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    int count[6] = {0};

    srand(time(0));

    for (int i = 0; i < 10000; i++) {
        int roll = rand() % 6 + 1;
        count[roll - 1]++;
    }

    for (int i = 0; i < 6; i++) {
        cout << "Value " << (i + 1) << " occurred "
             << count[i] << " times" << endl;
    }

    return 0;
}
