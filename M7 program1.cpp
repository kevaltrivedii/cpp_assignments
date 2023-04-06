#include <iostream>

int main() {
    // Dynamically allocate a single integer
    int* p = new int;
    *p = 42;

    std::cout << "The value at p is " << *p << std::endl;

    // Dynamically allocate an array of 5 integers
    int* arr = new int[5];
    for (int i = 0; i < 5; i++) {
        arr[i] = i*i;
    }

    std::cout << "The values in the array are: ";
    for (int i = 0; i < 5; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // Deallocate memory
    delete p;
    delete[] arr;

    return 0;
}
        