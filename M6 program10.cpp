#include <iostream>
using namespace std;

class Account {
    public:
        string name;
        int accno;
        string acctype;
        float balance;
        
        Account(string n, int a, string t, float b) {
            name = n;
            accno = a;
            acctype = t;
            balance = b;
        }
        
        void display_balance() {
            cout << "Account holder: " << name << endl;
            cout << "Account number: " << accno << endl;
            cout << "Account type: " << acctype << endl;
            cout << "Account balance: " << balance << endl;
        }
        
        virtual void deposit(float amount) {
            balance += amount;
            cout << "Amount of " << amount << " deposited.\n";
        }
        
        virtual void withdraw(float amount) {
            if (balance - amount >= 0) {
                balance -= amount;
                cout << "Amount of " << amount << " withdrawn.\n";
            } else {
                cout << "Insufficient funds.\n";
            }
        }
};

class Curr_Acc : public Account {
    public:
        Curr_Acc(string n, int a, float b) 
            : Account(n, a, "Current", b) {}
            
        float overdraft_limit = -1000; // assuming Rs. 1000 as overdraft limit
        
        void check_minimum_balance() {
            if (balance < 0 && balance > overdraft_limit) {
                balance -= 50; // assuming Rs. 50 penalty for negative balance
                cout << "Penalty of Rs. 50 has been applied for negative balance.\n";
            }
        }
};

class Sav_Acc : public Account {
    public:
        Sav_Acc(string n, int a, float b) 
            : Account(n, a, "Saving", b) {}
            
        float interest_rate = 0.05; // assuming 5% interest rate
        
        void add_interest() {
            balance *= (1 + interest_rate);
            cout << "Interest added to account.\n";
        }
};

int main() {
    Curr_Acc curr("John", 1001, 5000);
    cout << "\nCurrent Account\n";
    cout << "---------------\n";
    curr.display_balance();
    
    curr.deposit(2000);
    curr.check_minimum_balance();
    curr.withdraw(3000);
    curr.check_minimum_balance();
    
    cout << "\nUpdated account balance: " << curr.balance << endl;
    
    
    Sav_Acc sav("Jane", 2001, 10000);
    cout << "\nSaving Account\n";
    cout << "--------------\n";
    sav.display_balance();
    
    sav.deposit(5000);
    sav.add_interest();
    sav.withdraw(8000);
    
    cout << "\nUpdated account balance: " << sav.balance << endl;

    return 0;
}