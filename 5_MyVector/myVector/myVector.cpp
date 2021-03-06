#include "myVector.h"

size_t MyVector::getSize() const {
    return size;
}

size_t MyVector::getCapasity() const {
    return capasity;
}

std::ostream &operator << (std::ostream &os,  MyVector &vector){
    os << "\n\tVector" << "{";
    for (int i = 0; i < vector.size ; ++i)
        os << " " << vector.vec[i] << " ";
    os << "}" << std::endl;
    return os;
}

void MyVector::push_back(size_t elem) {
    resize(++size);
    vec[size - 1] = elem;
}

void MyVector::push_front(size_t elem) {
    resize(++size);
    for (int i = (size); i >= 0 ; --i) {
        int temp = vec[i++];
        vec[i] = temp;
        i--;
    }
    *vec = elem;
}

void MyVector::resize(size_t new_size) {
    if(size >= capasity) {
        capasity *= CAPACITY_MODIFIER;

        int *newMemory = new int[capasity];
        for (int i = 0; i < size; i++)
            newMemory[i] = vec[i];

        delete[] vec;
        vec = newMemory;
    }
    size = new_size;
}

void MyVector::pop_back() {
    vec[size-1] = 0;
    resize(--size);
}

void MyVector::pop_front() {
    for (int i = 0; i < size; ++i) {
        size_t temp = vec[i+1];
        vec[i] = temp;
    }
    resize(--size);
}

void MyVector::clear() {
    for (int i = 0; i < size; ++i)
        vec[i] = NULL;
    resize(0);
}

int MyVector::operator[](size_t index) {
//    if ((index < 0) || (index > size)) {
//        std::cout << "Error. Wrong adress of element! \n";
//    } else {
        return *(vec + index);
//    }
}


const int& MyVector::operator[](size_t index) const {
    return vec[index];
}







