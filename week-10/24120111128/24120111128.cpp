#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;
 
 
int loadData(const char fname[], int idArr[], int scoreArr[], int limit);
void showAll(int idArr[], int scoreArr[], int n);
void getStats(int scoreArr[], int n, double &avg, int &minVal, int &maxVal);
void gradeDist(int scoreArr[], int n, int &A, int &B, int &C, int &D, int &F);
int randomPass(int idArr[], int scoreArr[], int n);
void writeSummary(const char fname[], double avg, int mn, int mx,
                  int A, int B, int C, int D, int F, int total);


int main() {

    srand(time(0));

    const int MAX = 100;
    int idList[MAX];
    int scoreList[MAX];

    int n = loadData("scores.csv", idList, scoreList, MAX);
    cout << "Total Students Loaded: " << n << "\n\n";

    cout << "-- Student Records --\n";
    showAll(idList, scoreList, n);
    cout << endl;

    double avgScore;
    int low, high;

    getStats(scoreList, n, avgScore, low, high);

    cout << "Average: " << avgScore << "\n";
    cout << "Min Score: " << low << "\n";
    cout << "Max Score: " << high << "\n\n";

    int A, B, C, D, F;

    gradeDist(scoreList, n, A, B, C, D, F);

    cout << "A: " << A << "\nB: " << B << "\nC: " << C
         << "\nD: " << D << "\nF: " << F << "\n\n";

    int picked = randomPass(idList, scoreList, n);
    if (picked == -1) {
        cout << "No passing student.\n";
    } else {
        cout << "Random Passing Student -> ID: " << idList[picked]
             << ", Score: " << scoreList[picked] << "\n";
    }

    cout << endl;

    writeSummary("summary.csv", avgScore, low, high,
                 A, B, C, D, F, n);

    cout << "summary.csv created.\n";

    return 0;
}


// === PRINT ALL ===
void showAll(int idArr[], int scoreArr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "StudentID: " << idArr[i]
             << "   Score: " << scoreArr[i] << "\n";
    }
}


// === LOAD DATA ===
int loadData(const char fname[], int idArr[], int scoreArr[], int limit) {
    ifstream file(fname);
    if (!file.is_open()) {
        cout << "Could not open file!\n";
        return 0;
    }

    string line;
    getline(file, line); // header

    int count = 0;
    while (getline(file, line) && count < limit) {
        int comma = line.find(',');
        idArr[count] = stoi(line.substr(0, comma));
        scoreArr[count] = stoi(line.substr(comma + 1));
        count++;
    }

    return count;
}


void getStats(int scoreArr[], int n,
              double &avg, int &minVal, int &maxVal) {

    int sum = 0;
    minVal = scoreArr[0];
    maxVal = scoreArr[0];

    for (int i = 0; i < n; i++) {
        sum += scoreArr[i];

        if (scoreArr[i] < minVal) minVal = scoreArr[i];
        if (scoreArr[i] > maxVal) maxVal = scoreArr[i];
    }

    avg = (double)sum / n;
}


// === GRADE DISTRIBUTION ===
void gradeDist(int scoreArr[], int n,
               int &A, int &B, int &C,
               int &D, int &F) {

    A = B = C = D = F = 0;

    for (int i = 0; i < n; i++) {
        int s = scoreArr[i];

        if (s >= 70) A++;
        else if (s >= 60) B++;
        else if (s >= 50) C++;
        else if (s >= 45) D++;
        else F++;
    }
}


int randomPass(int idArr[], int scoreArr[], int n) {
    int pass[100];
    int c = 0;

    for (int i = 0; i < n; i++) {
        if (scoreArr[i] >= 50) {
            pass[c] = i;
            c++;
        }
    }

    if (c == 0) return -1;

    int r = rand() % c;
    return pass[r];
}


void writeSummary(const char fname[], double avg, int mn, int mx,
                  int A, int B, int C, int D, int F,
                  int total) {

    ofstream out(fname);

    out << "Metric,Value\n";
    out << "Number of Students," << total << "\n";
    out << "Average Score," << avg << "\n";
    out << "Minimum Score," << mn << "\n";
    out << "Maximum Score," << mx << "\n";
    out << "A Count," << A << "\n";
    out << "B Count," << B << "\n";
    out << "C Count," << C << "\n";
    out << "D Count," << D << "\n";
    out << "F Count," << F << "\n";
}
