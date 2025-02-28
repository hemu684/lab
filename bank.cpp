#include <iostream>
#include <cmath> // For pow function

using namespace std;

class BankAccount {
    double balance;
    double rateOfInterest;

public:
    // Constructor to initialize balance and rate of interest
    BankAccount(double initialBalance, double interestRate) {
        balance = initialBalance;
        rateOfInterest = interestRate;
    }

    // Destructor to display a message when the object is destroyed
    ~BankAccount() {
        cout << "\nBankAccount object is being destroyed." << endl;
    }

    // Method to make a deposit
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. Current balance: " << balance << endl;
    }

    // Method to withdraw an amount from the balance
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. Current balance: " << balance << endl;
        } else {
            cout << "Insufficient balance." << endl;
        }
    }

    // Method to calculate and return the compound interest
    double calculateCompoundInterest(int years) {
        double CI = balance * (pow((1 + rateOfInterest / 100), years) - 1);
        return CI;
    }

    // Method to display the balance amount
    void displayBalance() {
        cout << "Current balance: " << balance << endl;
    }

    // Method to display the menu options
    void displayMenu() {
        cout << "\nMenu:\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Calculate Compound Interest\n";
        cout << "4. Display Balance\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
    }
};

int main() {
    double initialBalance, interestRate;
    cout << "Enter initial balance: ";
    cin >> initialBalance;
    cout << "Enter rate of interest: ";
    cin >> interestRate;

    BankAccount account(initialBalance, interestRate);

    int choice;
    double amount;
    int years;

    while (true) {
        account.displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: ";
                cin >> amount;
                account.deposit(amount);
                break;
            case 2:
                cout << "Enter amount to withdraw: ";
                cin >> amount;
                account.withdraw(amount);
                break;
            case 3:
                cout << "Enter number of years: ";
                cin >> years;
                cout << "Compound Interest after " << years << " years: "
                     << account.calculateCompoundInterest(years) << endl;
                break;
            case 4:
                account.displayBalance();
                break;
            case 5:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }
}
