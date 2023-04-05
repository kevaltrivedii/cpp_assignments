#include <iostream>
using namespace std;

// Inline function to find multiplication of two numbers
inline int multiply(int a, int b) {
    return a * b;
}

// Inline function to find cubic value of a number
inline int cubic(int x) {
    return x * x * x;
}

int main() {
    int num1, num2;

    cout << "Enter first number: ";
    cin >> num1;
    cout << "Enter second number: ";
    cin >> num2;

    // Find multiplication of the given numbers using inline function
    int mul = multiply(num1, num2);
    cout << "Multiplication of " << num1 << " and " << num2 << " is " << mul << endl;

    // Find cubic value of the first number using inline function
    int cube = cubic(num1);
    cout << "Cubic value of " << num1 << " is " << cube << endl;

    return 0;
}
