#include <iostream>
using namespace std;

int main () {
    int day;
    cout<<"What is today ==> ";
    cin>>day;

    switch (day){
        case 0:
        case 6:
            cout<<"Weekend";
            break;
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            cout<<"Weekday";
            break;
        default:
            cout<<"Invalid day";
    }

    // if (day == 1 || day == 2 || day == 3 || day == 4 || day == 5){
    //     cout<<"Weekday";
    // }
    // else if (day == 0 || day == 6){
    //     cout<<"Weekend";
    // }
}