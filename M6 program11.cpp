#include <iostream>
using namespace std;

class Number {
    private:
        int num;
        
    public:
        Number(int n) {
            num = n;
        }
        
        friend void swap(Number& x, Number& y);
        
        void display() {
            cout << "Number: " << num << endl;
        }
};

void swap(Number& x, Number& y) {
    int temp = x.num;
    x.num = y.num;
    y.num = temp;
}

int main() {
    Number a(5);
    Number b(10);
    
    cout << "Before swapping:\n";
    a.display();
    b.display();
    
    swap(a, b);
    
    cout << "\nAfter swapping:\n";
    a.display();
    b.display();
    
    return 0;
}
