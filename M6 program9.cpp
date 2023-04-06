#include <iostream>
using namespace std;

class Account {
    public:
        int accno;
        string name;
        float balance;
        
        void deposit(float amount) {
            balance += amount;
            cout << "Amount of " << amount << " deposited.\n";
        }
        
        virtual void withdraw(float amount) = 0;
};

class Saving_Account : public Account {
    public:
        float interest_rate = 0.03; // assuming 3% interest rate
        
        void withdraw(float amount) override {
            if (balance - amount >= 0) {
                balance -= amount;
                cout << "Amount of " << amount << " withdrawn.\n";
            } else {
                cout << "Insufficient funds.\n";
            }
        }
        
        void add_interest() {
            balance *= (1 + interest_rate);
            cout << "Interest added to account.\n";
        }
};

class Current_Account : public Account {
    public:
        float minimum_balance = 500; // assuming Rs. 500 as minimum balance
        float service_charge = 50; // assuming Rs. 50 as service charge
        
        void withdraw(float amount) override {
            if (balance - amount >= minimum_balance) {
                balance -= amount;
                cout << "Amount of " << amount << " withdrawn.\n";
            } else {
                cout << "Insufficient funds.\n";
                if (balance < minimum_balance && balance >= service_charge) {
                    balance -= service_charge;
                    cout << "Service charge of Rs. " << service_charge << " has been applied.\n";
                }
            }
        }
};

int main() {
    Saving_Account saver;
    saver.accno = 1001;
    saver.name = "John";
    saver.balance = 5000;
    
    cout << "\nSaving Account\n";
    cout << "---------------\n";
    cout << "Account number: " << saver.accno << endl;
    cout << "Account holder name: " << saver.name << endl;
    cout << "Account balance: " << saver.balance << endl;
    
    saver.deposit(2000);
    saver.add_interest();
    saver.withdraw(3000);
    
    cout << "\nUpdated account balance: " << saver.balance << endl;
    
    
    Current_Account current;
    current.accno = 2001;
    current.name = "Jane";
    current.balance = 3000;
    
    cout << "\nCurrent Account\n";
    cout << "----------------\n";
    cout << "Account number: " << current.accno << endl;
    cout << "Account holder name: " << current.name << endl;
    cout << "Account balance: " << current.balance << endl;
    
    current.deposit(1000);
    current.withdraw(1500); // should pass
    current.withdraw(4000); // should fail and apply service charge
    
    cout << "\nUpdated account balance: " << current.balance << endl;

    return 0;
}
