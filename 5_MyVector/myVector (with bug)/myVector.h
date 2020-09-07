#ifndef MYVECTOR_MYVECTOR_H
#define MYVECTOR_MYVECTOR_H

#include <ostream>
#include <iostream>

class MyVector{
    static const size_t CAPACITY_MODIFIER = 2;

private:
    size_t *vec;
    size_t size;
    size_t capasity;
public:
    MyVector(size_t size):
            size(size),
            capasity(size + CAPACITY_MODIFIER)
    {
        vec = new size_t[capasity];
        for (int i = 0; i < size; ++i) {
            vec[i] = 0;
        }
    }

    MyVector(size_t size, int initial):
            size(size),
            capasity(size + CAPACITY_MODIFIER)
    {
        vec = new (std::nothrow) size_t[capasity];
        for (int i = 0; i < size; ++i) {
            vec[i] = initial;
        }
    }

    MyVector(): MyVector(0,0){}

    ~MyVector() {
        //std::cout << "\nObject destroied";
        delete[] vec;
    }

    size_t getSize() const;
    size_t getCapasity() const;

    size_t *getVec() const;

    friend std::ostream &operator << (std::ostream &os, MyVector &vector);

    void push_back(size_t elem) ;
    void push_front(size_t elem);

    void pop_back();
    void pop_front();

    void resize(size_t new_size);
    void clear();

    int operator[](size_t index);
    const int& operator[](size_t index) const;
};

#endif