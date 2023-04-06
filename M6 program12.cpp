#include<iostream>
using namespace std;

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {  // took static normal values
    int x = 10, y = 20;
    cout << "Before swapping: x = " << x << ", y = " << y << endl;
    swap(x, y);
    cout << "After swapping: x = " << x << ", y = " << y << endl;

    double a = 3.14, b = 2.71;///and double variables
    cout << "Before swapping: a = " << a << ", b = " << b << endl;
    swap(a, b);
    cout << "After swapping: a = " << a << ", b = " << b << endl;

    return 0;
}
