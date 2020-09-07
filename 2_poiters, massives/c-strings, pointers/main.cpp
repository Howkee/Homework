#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int size = 256;
    char strFir[size];
    char strSec[size];

    //! Lenght of c-string
    cout << "First string:";
    gets(strFir);
    cout << "Size of str:" << strlen(strFir) << endl;

    //  for meticulous // equivalent to strlen
    /*
    int lich = 0;
    for ( int i = 0; i < sizeof(strFir); ++i ) {
        if(strFir[i] == '\0'){
            break;
        } else {
            lich++;
        }
    }
    cout << "Size of str:" << lich << " "  << endl;
    */

    //! Comparison of strings
    cout << "Second string:";
    gets(strSec);

    cout << "Compsrisoning:" << endl;
    for ( int i = 0; i < size; i++) {
        if ((strFir[i] == '\0') && (strSec[i] == '\0')) {
            cout << "Strings: " << strFir << " & " << strSec << " are equal" << endl;
            break;
        } else {
            if ((strFir[i] < strSec[i]) || (strFir[i] == '\0')) {
                cout << "String: " << strSec << " - is bigger than string: " << strFir << endl;
                break;
            } else {
                if (( strSec[i] < strFir[i] ) || (strSec[i] == '\0')) {
                    cout << "String: " << strFir << " - is bigger than string: " << strSec << endl;
                    break;
                }
            }
        }
    }

    cout << "Compsrisoning(pointers):" << endl;
    for ( int i = 0; i < size; i++) {
        if ((*(strFir+i) == '\0') && (*(strSec+i) == '\0')) {
            cout << "Strings: " << strFir << " & " << strSec << " are equal" << endl;
            break;
        } else {
            if ((*(strFir+i) < strSec[i]) || (*(strFir+i) == '\0')) {
                cout << "String: " << strSec << " - is bigger than string: " << strFir << endl;
                break;
            } else {
                if (( *(strSec+i) < *(strFir+i) ) || (*(strSec+i) == '\0')) {
                    cout << "String: " << strFir << " - is bigger than string: " << strSec << endl;
                    break;
                }
            }
        }
    }
    return 0;
}