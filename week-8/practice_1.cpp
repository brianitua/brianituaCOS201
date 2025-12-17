#include <iostream>
using namespace std;

int main (){
    int i = 1;
    int sum = 0;
    while (i < 6) {
        sum += i;
        cout<<"When i is "<<i<<"\n";
        i++;
        cout<<"sum is "<<sum<<"\n";
        cout<<"New i is "<<i<<"\n";
    }
    cout<<"When i is "<<i<<" Loop breaks\n";
    
}