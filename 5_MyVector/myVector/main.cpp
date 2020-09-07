#include <iostream>
#include "myVector.h"

int main() {
    int a = 56;

    MyVector vector = MyVector(10,100);
    std::cout << "Vector:" << std::endl;
    std::cout << vector;
    std::cout << "Vector size: " << vector.getSize() << std::endl;
    std::cout << "Vector capasity: " << vector.getCapasity() << std::endl;

    vector.push_back(a);
    std::cout << "\nAdd element at the end: " << vector;


    vector.push_front(87);
    vector.push_front(120);
    std::cout << "\nAdd element to the top: " << vector;

    vector.pop_back();
    vector.pop_front();
    std::cout << "\nDelete te first&last elements: " << vector;

    std::cout << "\nElement on 5 position: " << vector[5] << std::endl;

    vector.clear();
    std::cout << "\nClear vector: " << vector << std::endl;

    return 0;
}