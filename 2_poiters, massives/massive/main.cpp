#include <iostream>

using namespace std;
int main() {

    int masSize;

    cout << "Mas size" << endl;
    cin >> masSize;
    int mas[masSize];

    cout << "Mas elements:" << endl;
    for (int i = 0; i < masSize; ++i) {
            cin >> mas[i];
    }

    int num;
    cout << "Number" << endl;
    cin >> num;

    //! Search
    for (int i = 0; i < masSize; ++i) {
        if (mas[i] == num) {
            cout << "Nymber position " << i + 1 << endl;
        } else {
            if (i == masSize - 1) {
                cout << "Not found" << endl;
            }
        }
    }

    //! Bubble sort
    int temp = 0;
    for (int j = 0; j < masSize; ++j) {
        for (int k = 0; k < masSize; ++k) {
            if (mas[k] > mas[k + 1]) {
                temp = mas[k];
                mas[k] = mas[k + 1];
                mas[k + 1] = temp;
            }
        }
    }
    for (int i = 0; i < masSize; ++i) {
        cout << mas[i] << "\t";
    }

    //! Binary search
    cout << "Enter the key:";
    int key, center, left = 0, right = masSize-1;
    cin >> key;
    while(left <= right ) {
        center = (left + right) / 2;
        if (mas[center] > key)
            right = center - 1;
        else if (mas[center] < key)
            left = center + 1;
                else {
            cout << "Number position - " << center << endl;
            return 0;
        }
    }
    cout << "Key is not found" << endl;
    return  0;
}