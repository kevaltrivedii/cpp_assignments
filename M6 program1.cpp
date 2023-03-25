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
      depositorName = name;
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

    void display() {
      cout << "Depositor Name: " << depositorName << endl;
      cout << "Account Number: " << accountNumber << endl;
      cout << "Account Type: " << accountType << endl;
      cout << "Balance: " << balance << endl;
    }
};
int main() {
  BankAccount myAccount("John", 12345, "Checking", 1000.0);
  myAccount.display(); 
  myAccount.deposit(500.0);
  myAccount.display(); 
  myAccount.withdraw(2000.0); 
  myAccount.withdraw(700.0);
  myAccount.display(); 
  return 0;
}

