// Module 7 Q-2 Write a program of to sort the array using templates


#include <iostream>
using namespace std;

template<typename T, size_t N>
void sortArray(T (&arr)[N]) {
    sort(arr, arr+N);
}

int main() {
    int intArr[] = {5, 2, 7, 1, 8};
    sortArray(intArr);

    cout << "Sorted int array: ";
    for (int i = 0; i < 5; i++) {
        cout << intArr[i] << " ";
    }
    cout << std::endl;

    float floatArr[] = {3.14, 1.414, 10.0, 2.718, 6.023};
    sortArray(floatArr);

    cout << "Sorted float array: ";
    for (int i = 0; i < 5; i++) {
        cout << floatArr[i] << " ";
    }
    cout << endl;

    return 0;
}
