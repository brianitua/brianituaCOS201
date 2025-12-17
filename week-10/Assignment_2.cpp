
#include <iostream>
using namespace std;

// Function to verify PIN
bool verifyPin(int correctPin) {
    int attempts = 3;
    int enteredPin;
    
    while (attempts > 0) {
        cout << "Enter your PIN: ";
        cin >> enteredPin;
        
        if (enteredPin == correctPin) {
            return true;
        }
        
        attempts--;
        if (attempts > 0) {
            cout << "Incorrect PIN. " << attempts << " attempt(s) remaining.\n";
        }
    }
    
    return false;
}

int main() {
    // Default settings
    double balance = 50000.0;
    double dailyLimit = 20000.0;
    double withdrawnToday = 0.0;
    int pin = 4321;
    
    // Verify PIN
    if (!verifyPin(pin)) {
        cout << "Account Locked. Please contact your bank.\n";
        return 1;
    }
    
    cout << "\nLogin successful!\n\n";
    
    // ATM Menu loop
    int choice;
    do {
        cout << "======== ATM MENU ========\n";
        cout << "1. View Balance\n";
        cout << "2. Deposit Cash\n";
        cout << "3. Withdraw Cash\n";
        cout << "4. Reset PIN\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "\n";
        
        switch (choice) {
            case 1: {
                cout << "Your current balance is: N" << balance << "\n\n";
                break;
            }
            case 2: {
                double amount;
                cout << "Enter amount to deposit: N";
                cin >> amount;
                if (amount > 0) {
                    balance += amount;
                    cout << "Deposit successful. New balance: N" << balance << "\n\n";
                } else {
                    cout << "Invalid amount.\n\n";
                }
                break;
            }
            case 3: {
                double amount;
                cout << "Enter amount to withdraw: N";
                cin >> amount;
                
                if (amount <= 0) {
                    cout << "Invalid amount.\n\n";
                } else if (amount > balance) {
                    cout << "Insufficient funds.\n\n";
                } else if (withdrawnToday + amount > dailyLimit) {
                    cout << "Daily withdrawal limit exceeded.\n\n";
                } else {
                    balance -= amount;
                    withdrawnToday += amount;
                    cout << "Withdrawal successful. New balance: N" << balance << "\n\n";
                }
                break;
            }
            case 4: {
                int newPin;
                cout << "Enter new PIN: ";
                cin >> newPin;
                pin = newPin;
                cout << "PIN reset successful.\n\n";
                break;
            }
            case 5: {
                cout << "Thank you for using our ATM. Goodbye!\n";
                break;
            }
            default: {
                cout << "Invalid choice. Please try again.\n\n";
            }
        }
    } while (choice != 5);
    
    return 0;
}