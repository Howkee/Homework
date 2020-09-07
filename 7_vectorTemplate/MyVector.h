#ifndef VECTORTEMPLATE_MYVECTOR_H
#define VECTORTEMPLATE_MYVECTOR_H

#include <iostream>

template <class T>
class MyVector;

template<class T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &vector);

template <class T>
class MyVector {
    static const size_t CAPACITY_MODIFIER = 2;

private:
    T *vec;
    size_t size;
    size_t capasity;
public:
    MyVector(size_t size):
            size(size), capasity(size * CAPACITY_MODIFIER)
    {
        vec = new T[capasity];
        for (int i = 0; i < size; ++i) {
            vec[i] = 0;
        }
    }

    MyVector(size_t size, T initial):
            size(size), capasity(size * CAPACITY_MODIFIER)
    {
        vec = new (std::nothrow) T[capasity];
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

    T operator[](size_t index);
    const T& operator[](size_t index) const;

    void push_back(T elem) ;
    void push_front(T elem);

    void pop_back();
    void pop_front();

    void resize(size_t new_size);
    void clear();

    template<class M>
    friend std::ostream &operator << (std::ostream &os, const  MyVector<M> &vector);
};

//! geters
template<class T>
size_t MyVector<T>::getSize() const {
    return size;
}

template<class T>
size_t MyVector<T>::getCapasity() const {
    return capasity;
}

//!operator []
template<class T>
T MyVector<T>::operator[](size_t index) {
    return *(vec + index);
}

template<class T>
const T& MyVector<T>::operator[](size_t index) const {
    return vec[index];
}

//! push & pop
template<class T>
void MyVector<T>::push_back(T elem) {
    resize(++size);
    vec[size - 1] = elem;
}

template<class T>
void MyVector<T>::push_front(T elem) {
    resize(++size);
    for (int i = (size); i >= 0 ; --i) {
        std::swap(vec[i+1], vec[i]);
    }
    *vec = elem;
}

template<class T>
void MyVector<T>::pop_back() {
    resize(--size);
}

template<class T>
void MyVector<T>::pop_front() {
    for (int i = 0; i < size; ++i) {
        T temp = vec[i+1];
        vec[i] = temp;
    }
    resize(--size);
}

//!size change & <<
template<class T>
void MyVector<T>::clear() {
    resize(0);
}

template<class T>
void MyVector<T>::resize(size_t new_size) {
    if(size >= capasity) {
        capasity *= CAPACITY_MODIFIER;

        T *newMemory = new T[capasity];
        for (int i = 0; i < size; i++)
            newMemory[i] = vec[i];

        delete[] vec;
        vec = newMemory;
    }
    size = new_size;
}

template<class T>
std::ostream &operator<<(std::ostream &os, const MyVector<T> &vector) {
    os << "\nVector" << "{";
    for (int i = 0; i < vector.size ; ++i)
        os << " \"" << vector.vec[i] << "\" ";
    os << "}";
    return os;
}

#endif