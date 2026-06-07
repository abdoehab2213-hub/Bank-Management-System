// OOP Project (Bank System).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BankSystem.h"
using namespace std;

void showMenu() {
    cout << "\n--- Advanced Bank Management System ---\n";
    cout << "1. Add New Account\n";
    cout << "2. Deposit Money\n";
    cout << "3. Withdraw Money\n";
    cout << "4. Transfer Money\n";
    cout << "5. Display All Accounts\n";
    cout << "6. Exit & Save\n";
    cout << "Enter your choice: ";
}

int main() {
    BankSystem bank; // هيعمل Load تلقائي هنا
    int choice, typeChoice, id, targetId;
    double amount;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Select Account Type (1. Savings, 2. Current): ";
            cin >> typeChoice;
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter Initial Balance: ";
            cin >> amount;
            bank.addAccount(typeChoice, id, amount);
            break;
        case 2:
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter Deposit Amount: ";
            cin >> amount;
            bank.depositTo(id, amount);
            break;
        case 3:
            cout << "Enter Account ID: ";
            cin >> id;
            cout << "Enter Withdraw Amount: ";
            cin >> amount;
            bank.withdrawFrom(id, amount);
            break;
        case 4:
            cout << "Enter Your Account ID: ";
            cin >> id;
            cout << "Enter Target Account ID: ";
            cin >> targetId;
            cout << "Enter Transfer Amount: ";
            cin >> amount;
            bank.transfer(id, targetId, amount);
            break;
        case 5:
            bank.displayAllAccounts();
            break;
        case 6:
            cout << "Saving data... Thank you for using our Bank System. Goodbye!\n";
            break; // الـ Destructor بتاع كلاس bank هيشتغل هنا تلقائي ويسيف
        default:
            cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
