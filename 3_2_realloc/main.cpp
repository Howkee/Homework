#include <iostream>

void* my_realloc(void *ptr, const size_t &old_size, const size_t &new_size) {
    char *newMemory = static_cast<char *>(ptr);
    char *new_ptr = new char[new_size];

    for (int i = 0; i < old_size; ++i) {
        new_ptr[i] = newMemory[i];
    }

    ptr = new_ptr;
    //delete[](new_ptr);
    return ptr ;
}

int main()
{
    int size = 10;
    int newSize = size * 3;
    auto *intMemory = new char[size];

    for (int i = 0; i < size; i++)
        intMemory[i] = 65;

   my_realloc(intMemory, sizeof(*intMemory) * size, sizeof(*intMemory) * newSize);

   for (int i = size; i < newSize; i++)
       intMemory[i] = 66;


    for (int i = newSize-10; i < newSize; i++)
        intMemory[i] = 67;

    for (int i = 0; i < newSize; i++)
        std::cout << intMemory[i] << " ";

    //delete[] intMemory;
    return 0;
}