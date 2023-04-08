// Module 6 Q-9  Assume that a bank maintains two kinds of accounts for customer, 
// one called as saving account and other as current accounts provides Simple interest and withdraw facilities but no Cheque book facility.
// a) The current account provides Cheque book facility but no interest.
// b) Current account holders should maintain a minimum balance and if the balance falls below this level a service charges is imposed




#include <iostream>
using namespace std;

class Account {
    public:
        int accno;      //account number
        string name;    //account holder name
        float balance;  //account balance
        
        void deposit(float amount) {    //function to deposit an amount in the account
            balance += amount;
            cout << "Amount of " << amount << " deposited.\n";
        }
        
        virtual void withdraw(float amount) = 0;     //used of virtual function to call correct function ia pointer ,
//     virtual function to withdraw money from the account
};

class Saving_Account : public Account {     //derived class Saving_Account from base class Account
    public:
        float interest_rate = 0.03;     //interest rate assumed as 3%
        
        void withdraw(float amount) override {    //overriding the withdraw function
            if (balance - amount >= 0) {
                balance -= amount;
                cout << "Amount of " << amount << " withdrawn.\n";
            } else {
                cout << "Insufficient funds.\n";
            }
        }
        
        void add_interest() {   //function to add interest to account balance
            balance *= (1 + interest_rate);
            cout << "Interest added to account.\n";
        }
};

class Current_Account : public Account {   //derived class Current_Account from base class Account
    public:
        float minimum_balance = 500;    //minimum balance assumed as Rs. 500
        float service_charge = 50;      //service charge assumed as Rs. 50
        
        void withdraw(float amount) override {    //overriding the withdraw function
            if (balance - amount >= minimum_balance) { 
            //checking if the withdrawal amount exceeds the minimum balance
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
    Saving_Account saver;   //creating an instance of Saving_Account class
    saver.accno = 1001;     //setting account number
    saver.name = "John";    //setting account holder name
    saver.balance = 5000;   //setting initial account balance
    
    //displaying details of the account before performing any operation
    cout << "\nSaving Account\n";
    cout << "---------------\n";
    cout << "Account number: " << saver.accno << endl;
    cout << "Account holder name: " << saver.name << endl;
    cout << "Account balance: " << saver.balance << endl;
    
    saver.deposit(2000);    //depositing Rs. 2000
    saver.add_interest();   //adding interest to account balance
    saver.withdraw(3000);   //withdrawing Rs. 3000
    
    //displaying updated account balance after performing above operations
    cout << "\nUpdated account balance: " << saver.balance << endl;
    
    
    Current_Account current;    //creating an instance of Current_Account class
    current.accno = 2001;       //setting account number
    current.name = "Jane";      //setting account holder name
    current.balance = 3000;     //setting initial account balance
    
    //displaying details of the account before performing any operation
    cout << "\nCurrent Account\n";
    cout << "----------------\n";
    cout << "Account number: " << current.accno << endl;
    cout << "Account holder name: " << current.name << endl;
    cout << "Account balance: " << current.balance << endl;
    
    current.deposit(1000);          //depositing Rs. 1000
    current.withdraw(1500);         //withdrawing Rs. 1500,
    current.withdraw(4000);         //withdrawing Rs. 4000, 
    
    //displaying updated account balance after performing above operations
    cout << "\nUpdated account balance: " << current.balance << endl;

    return 0;   
}
