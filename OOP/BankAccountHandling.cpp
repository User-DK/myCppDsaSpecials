#include <iostream>
#include <string>
#include <map>
using namespace std;

class NegativeBalanceException : public exception {
public:
    // Provide a custom exception message
    const char* what() const throw() {
        return "Negative Balance Exception: Cannot withdraw more than the current balance.";
    }
};

class BankAccount {
private:
    // Use a map to store account numbers and their associated details (name and balance)
    static map<int, pair<string, int>> accounts;
    static int counter;

public:

    // Constructor for new Account
    BankAccount(string accHolName, int currBalance) {
        int accNumber = counter++;
        accounts[accNumber] = make_pair(accHolName, currBalance);
        cout << "\nAccount number for " << accHolName << " is " << accNumber;
    }

    // Constructor for Deposit/Withdraw
    BankAccount(int accNumber, int Amount, int operation) {
        try {
            if (accounts.find(accNumber) == accounts.end()) {
                cout << "\nAccount with this number does not exist.";
            } else {
                if (operation == 0) { // Deposit
                    accounts[accNumber].second += Amount;
                    cout << "\nDeposited " << Amount << " into account number " << accNumber;
                } else if (operation == 1) { // Withdraw
                    if (Amount <= accounts[accNumber].second) {
                        accounts[accNumber].second -= Amount;
                        cout << "\nDebited " << Amount << " from account number " << accNumber;
                    } else {
                        NegativeBalanceException a;
                        throw a;
                    }
                }
            }
        }catch (std::exception& e) {
            cerr << "Exception: " << e.what() << endl;
        }
    }

    // Check the account balance
    BankAccount(int accNumber, int operation) {
        if (operation == 2) {
            if (accounts.find(accNumber) == accounts.end()) {
                cout << "\nAccount with this number does not exist.";
            } else {
                cout << "\nAccount balance for account number " << accNumber << " is " << accounts[accNumber].second;
            }
        }
    }
};

int BankAccount::counter = 22510000; 
map<int, pair<string, int>> BankAccount::accounts;


int main() {
    cout << "\nWelcome to the Official Bank Account page";

    while (true) {
        cout << "\nChoose an option:\na. Create a new account\nb. Deposit money into an account\nc. Withdraw money from an account\nd. Check the account balance\ne. Quit the program\n";
        char c;
        cin >> c;

        switch (c) {
        case 'a': {
            string accHolName;
            int currBalance;
            cout << "\nEnter Account Holder's Name: ";
            cin >> accHolName;
            cout << "\nEnter the Account Balance: ";
            cin >> currBalance;
            BankAccount(accHolName, currBalance);
        } break;

        case 'b': {
            int accNumber;
            int depositAmount;
            cout << "\nEnter the Account Number: ";
            cin >> accNumber;
            cout << "\nEnter the Amount to be Deposited: ";
            cin >> depositAmount;
            BankAccount(accNumber, depositAmount, 0);
        } break;

        case 'c': {
            int accNumber1;
            int withDrawAmount;
            cout << "\nEnter the Account Number: ";
            cin >> accNumber1;
            cout << "\nEnter the Amount to be Withdrawn: ";
            cin >> withDrawAmount;
            BankAccount(accNumber1, withDrawAmount, 1);
        } break;

        case 'd': {
 int accountNumber;
    cout << "\nEnter the Account Number: ";
    cin >> accountNumber;
    BankAccount(accountNumber, 2); // Use operation 2 to indicate checking balance
        } break;

        case 'e': {
            cout << "Exiting the program." << endl;
            return 0;
        } break;

        default: {
            cout << "Invalid option. Please try again." << endl;
        }
        break;
        }
    }
}
