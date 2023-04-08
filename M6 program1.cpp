//module 6 Q-1 Define a class to represent a bank account. Include the following members:
// Data Member
// a) Name of the depositor -
// b) Account Number
// c) Type of Account -
// d) Balance amount in the account -
// e) Member Functions -
// f) To assign values -
// g) To deposited an amount -
// h) To withdraw an amount after checking balance -
// i) To display name and balance


#include <iostream>
using namespace std;

class BankAccount {
  private:
    string depositorName;
    int accountNumber;
    string accountType;
    double balance;

  public:
  
    BankAccount(string name, int accNum, string accType, double bal) {
      depositorName = name; //pointers
      accountNumber = accNum;
      accountType = accType;
      balance = bal;
    }

    
    void deposit(double amount) {
      balance += amount;
    }

    void withdraw(double amount) {
      if (amount > balance) {
        cout << "Insufficient balance" << endl;
      } else {
        balance -= amount;
      }
    }

    void display() {//diplayed depositor details
      cout << "Depositor Name: " << depositorName << endl;
      cout << "Account Number: " << accountNumber << endl;
      cout << "Account Type: " << accountType << endl;
      cout << "Balance: " << balance << endl;
    }
};
int main() { //used static input
  //and called functions into main.
  BankAccount myAccount("John", 12345, "Checking", 1000.0);
  myAccount.display(); 
  myAccount.deposit(500.0);
  myAccount.display(); 
  myAccount.withdraw(2000.0); 
  myAccount.withdraw(700.0);
  myAccount.display(); 
  return 0;
}

