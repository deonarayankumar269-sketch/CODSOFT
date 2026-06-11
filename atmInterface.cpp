#include <iostream>
using namespace std;

// Bank Account Class
class BankAccount
{
private:
    double balance;

public:
    // Constructor
    BankAccount(double initialBalance)
    {
        balance = initialBalance;
    }

    // Deposit Method
    void deposit(double amount)
    {
        if(amount > 0)
        {
            balance += amount;
            cout << "\nAmount Deposited Successfully!" << endl;
        }
        else
        {
            cout << "\nInvalid Deposit Amount!" << endl;
        }
    }

    // Withdraw Method
    bool withdraw(double amount)
    {
        if(amount <= 0)
        {
            cout << "\nInvalid Withdrawal Amount!" << endl;
            return false;
        }

        if(amount > balance)
        {
            cout << "\nInsufficient Balance!" << endl;
            return false;
        }

        balance -= amount;
        cout << "\nWithdrawal Successful!" << endl;
        return true;
    }

    // Check Balance Method
    void checkBalance()
    {
        cout << "\nCurrent Balance: Rs. " << balance << endl;
    }
};

// ATM Class
class ATM
{
private:
    BankAccount &account;

public:
    ATM(BankAccount &acc) : account(acc) {}

    void displayMenu()
    {
        int choice;
        double amount;

        do
        {
            cout << "\n===== ATM MENU =====";
            cout << "\n1. Check Balance";
            cout << "\n2. Deposit Money";
            cout << "\n3. Withdraw Money";
            cout << "\n4. Exit";
            cout << "\nEnter your choice: ";
            cin >> choice;

            switch(choice)
            {
                case 1:
                    account.checkBalance();
                    break;

                case 2:
                    cout << "\nEnter amount to deposit: Rs. ";
                    cin >> amount;
                    account.deposit(amount);
                    break;

                case 3:
                    cout << "\nEnter amount to withdraw: Rs. ";
                    cin >> amount;
                    account.withdraw(amount);
                    break;

                case 4:
                    cout << "\nThank you for using ATM!" << endl;
                    break;

                default:
                    cout << "\nInvalid Choice! Try Again." << endl;
            }

        } while(choice != 4);
    }
};

// Main Function
int main()
{
    double initialBalance;

    cout << "===== ATM INTERFACE SYSTEM =====\n";

    cout << "Enter Initial Account Balance: Rs. ";
    cin >> initialBalance;

    while(initialBalance < 0)
    {
        cout << "Invalid Balance! Enter again: ";
        cin >> initialBalance;
    }

    BankAccount userAccount(initialBalance);

    ATM atm(userAccount);

    atm.displayMenu();

    return 0;
}