#include <iostream>
using namespace std;

int main (){
    //Chinese zodaic based on a twelve year cycle 0-11

    int birth_year;
    cout<<"Enter the year ==> ";
    cin>>birth_year;
    int year = birth_year % 12;

    switch (year) {
        case 0:
            cout<< "Monkey";
            break;
        case 1:
            cout<<"Rooster";
            break;
        case 2:
            cout<<"Dog";
            break;
        case 3:
            cout<<"Pig";
            break;
        case 4:
            cout<<"Rat";
            break;
        case 5:
            cout<<"Ox";
            break;
        case 6:
            cout<<"Tiger";
            break;
        case 7:
            cout<<"Rabbit";
            break;
        case 8:
            cout<<"Dragon";
            break;
        case 9:
            cout<<"Snake";
            break;
        case 10:
            cout<<"Horse";
            break;
        case 11:
            cout<<"Sheep";
            break;
        default:
            cout<<"Invalid year";
    }
}