#include <iostream>
#include "myVector.h"

int main() {
    int a = 56;

    MyVector vector = MyVector(10,65);
    std::cout << vector;
    MyVector vector1 = MyVector(20);
    std::cout << vector1;
    MyVector vector2 = MyVector();

    vector2.push_back(a);
    vector2.push_back(45);
    vector2.push_back(12436587);

    vector2.push_front(87);
    vector2.push_front(120);

    std::cout << vector2;
    vector2.pop_back();
    vector2.pop_front();

    std::cout << vector2;

    vector.clear();
    std::cout << vector;

    MyVector vector3 = MyVector(10,65);

    std::cout << vector[3];
    return 0;
}