#include <iostream>
#include "functions.hpp"

using std::cout;
using std::endl;

int main() {

    double a = 2;
    int b = -100;
    char str[30] = "Do your best! Or do nothing";
    int arr[] = {4,6,8,2,4,7,9,10};
    auto size = 10;

    int *masMemory = new int[size];
    if (!masMemory)
        cout << "allocation of memory failed\n";
    else
    {
        for (int i = 0; i < size; i++)
            masMemory[i] = i+1;
    }

    cout << endl << "____________________________" << endl;
    // Максимальне з двох
    int Max = max(3,a);
    cout << Max << endl;
    cout << endl << "FACTORIAL:" << endl;
    cout << "Factorial 0 - " << factorial(0) << endl;
    cout << "Factorial recurs 5 - " << factorialRec(5) << endl;

    cout << endl << "POW:" << endl;
    // Піднесення до степення
    cout << a << "e" << b << " - ";
    myPrint(static_cast<double>(MyPow(2,b)));

    cout << endl << "OVERLOAD FUNCTION:" << endl;
    myPrint(str);

    cout << endl << "QSORT:" << endl;
    // Сортування через qsort
    qsort(arr, sizeof(arr)/ sizeof(arr[0]), sizeof(int), compare);
    for ( int i = 0; i < (sizeof(arr)/ sizeof(arr[0])); i++)
        std::cout << arr[i] << " ";

    cout << endl << "\nREALLOC:" << endl;
    int newSize = size * 2;
    masMemory = myRealloc(masMemory, size, newSize);

    for (int i = 0; i < size; i++)
        cout << masMemory[i] << " ";

    delete[] masMemory;
    return 0;
}