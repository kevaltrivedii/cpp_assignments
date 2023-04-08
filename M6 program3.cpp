//Module 6 Q-3  Write a program of find the simple interest using constructor with dynamic initialization. 
// Make constructor like Interest (int principal, int year, int rate) Interest (int principal, int year, float rate = 2.5)

#include <iostream>
using namespace std;

class Interest {
private:
    int principal;
    int year;
    float rate;

public:
    // Constructor with dynamic initialization (rate is with default value of 2.5%)
    Interest(int p, int y, float r = 2.5) {
        this->principal = p;
        this->year = y;
    }
    //applied simple interest formula
    float calculateSimpleInterest() {
        return (principal * year * 2.5) / 100;
    }
};

int main() {
    int p, y;
    float r,SI;

    cout << "Enter principal: ";
    cin >> p;
    cout << "Enter year: ";
    cin >> y;
    
    //call interest function formula
    Interest obj(p, y);
     SI = obj.calculateSimpleInterest();

    cout << "Simple Interest = " << SI;

    return 0;
}
