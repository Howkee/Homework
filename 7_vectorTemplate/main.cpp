#include <iostream>
#include "MyVector.h"

int main() {
    char a = 'a';
    int b = 65;

    MyVector<char> vector = MyVector<char>(10,a);

    vector.push_front('b');
    vector.push_back('c');

    MyVector<std::string> vector1 = MyVector<std::string>(10,"String");

    vector1.pop_front();
    vector1.pop_back();
    vector1.push_back("vector end");

    MyVector<int> vector2 = MyVector<int>(10,b);

    std::cout << vector;
    std::cout << vector1;
    std::cout << vector2;
    vector2.clear();
    std::cout << vector2;


}