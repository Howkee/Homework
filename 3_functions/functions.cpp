#include <ostream>
#include <iostream>
#include "functions.hpp"

int max(int a, int b){
    return (a < b)? b : a;
}

int factorialRec(int x){
    if(x < 1)
         return 1;
    else
        return factorialRec(x - 1) * x;
}

long double MyPow(double x, int y) {
   long double rez = 1;
    if (y < 0) {
        while (y != 0) {
            rez *= x;
            y++;
        }
        rez = 1/rez;
    }
    else {
        while (y != 0) {
            rez *= x;
            y--;
        }
    }
    return rez;
}

int compare(const void * x1, const void * x2){
    return (*(int*)x1 - *(int*)x2);
}

void myPrint(int a){
    std::cout << "Integer: " << a << std::endl;
}
void myPrint(double a){
    std::cout << "Double: " << a << std::endl;
}
void myPrint(char* a){
    std::cout << "String: " << a << std::endl;
}

//_____лише для інта: ПЕРЕРОБИТИ
int* myRealloc(int *masMemory, int &size, int newSize){
    int *newMemory = new int[newSize];
    for (int i = 0; i < size; i++)
        newMemory[i] = masMemory[i];
    delete[] masMemory;
    size = newSize;
    return newMemory;
}