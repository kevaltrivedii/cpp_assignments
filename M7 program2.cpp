#include <iostream>
#include <algorithm>

template<typename T, size_t N>
void sortArray(T (&arr)[N]) {
    std::sort(arr, arr+N);
}

int main() {
    int intArr[] = {5, 2, 7, 1, 8};
    sortArray(intArr);

    std::cout << "Sorted int array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << intArr[i] << " ";
    }
    std::cout << std::endl;

    float floatArr[] = {3.14, 1.414, 10.0, 2.718, 6.023};
    sortArray(floatArr);

    std::cout << "Sorted float array: ";
    for (int i = 0; i < 5; i++) {
        std::cout << floatArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
