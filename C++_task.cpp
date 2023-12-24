#include <iostream>
#include <string>
using namespace std;

const int MAX_ACCOUNTS = 100;


class Account {
private:
    string name;
    string nid;
    string dob;
    string tin;
    double balance;

public:
    Account(string name, string nid, string dob, string tin) {
        this->name = name;
        this->nid = nid;
        this->dob = dob;
        this->tin = tin;
        this->balance = 0;
    }

    string getName() { return name; }

    string getNid() { return nid; }

    string getDob() { return dob; }

    string getTin() { return tin; }

    double getBalance() { return balance; }

    void setName(string name) { this->name = name; }

    void setDob(string dob) { this->dob = dob; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. Your new balance is " << balance << endl;
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0) {
            if (balance >= amount) {
                if (balance - amount > 500) {
                    balance -= amount;
                    cout << "Withdrawal successful. Your new balance is " << balance << endl;
                } else {
                    cout << "Insufficient balance. You must keep at least 500 in your account." << endl;
                }
            } else {
                cout << "Insufficient balance. You cannot withdraw more than your balance." << endl;
            }
        } else {
            cout << "Invalid amount. Please enter a positive value." << endl;
        }
    }
};


class Bank {
private:
    Account accounts[MAX_ACCOUNTS];
    int numAccounts;

public:
    Bank() : numAccounts(0) {}

    void createAccount() {
        if (numAccounts < MAX_ACCOUNTS) {
            string name, nid, dob, tin;
            cout << "Enter your name: ";
            cin >> name;
            cout << "Enter your national ID: ";
            cin >> nid;
            cout << "Enter your date of birth: ";
            cin >> dob;
            cout << "Enter your tax identification number: ";
            cin >> tin;
            accounts[numAccounts++] = Account(name, nid, dob, tin);
            cout << "Account created successfully." << endl;
        } else {
            cout << "Maximum number of accounts reached." << endl;
        }
    }

    void updateAccount() {
        string nid;
        cout << "Enter your national ID: ";
        cin >> nid;
        bool found = false;
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getNid() == nid) {
                found = true;
                string name, dob;
                cout << "Enter your new name: ";
                cin >> name;
                cout << "Enter your new date of birth: ";
                cin >> dob;
                accounts[i].setName(name);
                accounts[i].setDob(dob);
                cout << "Account updated successfully." << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found. Please enter a valid ID." << endl;
        }
    }

    void depositToAccount() {
        string nid;
        cout << "Enter your national ID: ";
        cin >> nid;
        bool found = false;
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getNid() == nid) {
                found = true;
                double amount;
                cout << "Enter the amount to deposit: ";
                cin >> amount;
                accounts[i].deposit(amount);
                break;
            }
        }
        if (!found) {
            cout << "Account not found. Please enter a valid ID." << endl;
        }
    }

    void withdrawFromAccount() {
        string nid;
        cout << "Enter your national ID: ";
        cin >> nid;
        bool found = false;
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getNid() == nid) {
                found = true;
                double amount;
                cout << "Enter the amount to withdraw: ";
                cin >> amount;
                accounts[i].withdraw(amount);
                break;
            }
        }
        if (!found) {
            cout << "Account not found. Please enter a valid ID." << endl;
        }
    }

    void showAccount() {
        string nid;
        cout << "Enter your national ID: ";
        cin >> nid;
        bool found = false;
        for (int i = 0; i < numAccounts; i++) {
            if (accounts[i].getNid() == nid) {
                found = true;
                cout << "Account details:" << endl;
                cout << "Name: " << accounts[i].getName() << endl;
                cout << "National ID: " << accounts[i].getNid() << endl;
                cout << "Date of birth: " << accounts[i].getDob() << endl;
                cout << "Tax identification number: " << accounts[i].getTin() << endl;
                cout << "Balance: " << accounts[i].getBalance() << endl;
                break;
            }
        }
        if (!found) {
            cout << "Account not found. Please enter a valid ID." << endl;
        }
    }
};

void showMenu() {
    cout << "Welcome to the banking application." << endl;
    cout << "Please choose one of the following options:" << endl;
    cout << "1. Create a new account" << endl;
    cout << "2. Update an existing account" << endl;
    cout << "3. Deposit to an existing account" << endl;
    cout << "4. Withdraw from an existing account" << endl;
    cout << "5. Show an existing account" << endl;
    cout << "6. Exit the application" << endl;
}

int main() {
    Bank bank;
    int choice;
    do {
        showMenu();
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            bank.createAccount();
            break;
        case 2:
            bank.updateAccount();
            break;
        case 3:
            bank.depositToAccount();
            break;
        case 4:
            bank.withdrawFromAccount();
            break;
        case 5:
            bank.showAccount();
            break;
        case 6:
            cout << "Thank you for using the banking application. Goodbye." << endl;
            break;
        default:
            cout << "Invalid choice. Please enter a valid option." << endl;
            break;
