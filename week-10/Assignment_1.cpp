#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>
#include <cstdlib>

int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    std::string fullName;
    int jambScore;
    double waecAvg;
    int age;
    int firstChoiceInt;
    int disciplinaryInt;
    int hostelChoice;

    const double baseTuition = 1500000.0;
    const double hostelMainFee = 180000.0;
    const double hostelAnnexFee = 120000.0;
    const double hostelDayFee = 0.0;
    const double meritGrantAmount = 50000.0;

    cout << "Enter full name: ";
    std::getline(cin, fullName);

    cout << "Enter JAMB score: ";
    cin >> jambScore;

    cout << "Enter WAEC average: ";
    cin >> waecAvg;

    cout << "Enter age: ";
    cin >> age;

    cout << "First choice PAU? (1/0): ";
    cin >> firstChoiceInt;
    bool firstChoice = (firstChoiceInt != 0);

    cout << "Any disciplinary record? (1/0): ";
    cin >> disciplinaryInt;
    bool disciplinaryRecord = (disciplinaryInt != 0);

    cout << "Hostel (1=Main, 2=Annex, 3=Day): ";
    cin >> hostelChoice;

    std::string admissionStatus;
    if (disciplinaryRecord || age < 15) {
        admissionStatus = "Rejected";
    } else {
        bool criteria1 = (jambScore >= 220 && waecAvg >= 60 && firstChoice);
        bool criteria2 = (jambScore >= 200 && waecAvg >= 70);

        if (criteria1 || criteria2)
            admissionStatus = "Admitted";
        else
            admissionStatus = "Pending";
    }

    double scholarshipPercent = 0.0;
    if (admissionStatus == "Admitted") {
        if (jambScore >= 320)
            scholarshipPercent = 30.0;
        else if (jambScore >= 280)
            scholarshipPercent = 20.0;
        else if (jambScore >= 240)
            scholarshipPercent = 10.0;
        else
            scholarshipPercent = 0.0;

        if (waecAvg >= 80.0 && firstChoice) {
            scholarshipPercent += 5.0;

            if (scholarshipPercent > 35.0)
                scholarshipPercent = 35.0;
        }
    }

    std::string hostelStatus;
    double hostelFee = 0.0;

    if (admissionStatus == "Admitted" && !disciplinaryRecord) {
        if (hostelChoice == 1) {
            hostelStatus = "Main Hostel";
            hostelFee = hostelMainFee;
        } else if (hostelChoice == 2) {
            hostelStatus = "Annex Hostel";
            hostelFee = hostelAnnexFee;
        } else {
            hostelStatus = "Day Student";
            hostelFee = hostelDayFee;
        }

    } else if (admissionStatus == "Pending") {
        hostelStatus = "On Hold";
        hostelFee = 0.0;

    } else {
        hostelStatus = "Not Applicable";
        hostelFee = 0.0;
    }

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int r = std::rand() % 100 + 1;

    bool isPrime =
        r == 2 || r == 3 || r == 5 || r == 7 || r == 11 || r == 13 || r == 17 || r == 19 ||
        r == 23 || r == 29 || r == 31 || r == 37 || r == 41 || r == 43 || r == 47 ||
        r == 53 || r == 59 || r == 61 || r == 67 || r == 71 || r == 73 || r == 79 ||
        r == 83 || r == 89 || r == 97;

    double meritGrantApplied = 0.0;
    if (admissionStatus == "Admitted" && isPrime && r <= 97) {
        meritGrantApplied = meritGrantAmount;
    }

    double tuitionAfterScholarship =
        baseTuition - (scholarshipPercent / 100.0) * baseTuition;

    double totalPayable = tuitionAfterScholarship + hostelFee - meritGrantApplied;

    if (totalPayable < 0.0)
        totalPayable = 0.0;

    cout << endl;
    cout << "Name: " << fullName << endl;
    cout << "Admission Status: " << admissionStatus << endl;

    cout << std::fixed << std::setprecision(2);
    cout << "Scholarship: " << scholarshipPercent
         << "%  Tuition After Scholarship: \u20A6"
         << tuitionAfterScholarship << endl;

    cout << "Hostel: " << hostelStatus
         << "  Fee: \u20A6" << hostelFee << endl;

    cout << "Random draw: " << r
         << "   Merit Grant: \u20A6" << meritGrantApplied << endl;

    cout << "TOTAL PAYABLE: \u20A6" << totalPayable << endl;

    return 0;
}
