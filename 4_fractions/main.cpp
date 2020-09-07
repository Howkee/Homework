#include <iostream>
#include <regex>
#include "fraction.h"

using std::cout;
using std::endl;

int main() {
    Fraction fraction = Fraction(2,3);
    Fraction fraction1 = Fraction(1,5);
    Fraction fraction2 = Fraction(1,5);

    Fraction fraction3;
    cin >> fraction3;

    lmc(fraction,fraction1);

    Fraction result = fraction;
    cout <<"1." << result << endl;

    result = fraction1;
    cout <<"2." <<  result << endl;

    if(result == fraction1){
        cout << "3.Fractions are equal" << endl;
    }

    if(result != fraction){
        cout << "4.Fractions is not equal" << endl;
    }

    cout << "5." << (fraction1 + fraction2) << endl;

    if(fraction > fraction1){
        cout << "6.Fraction " << fraction.getNumerator() << "/" << fraction.getDenominator() << " is bigger." << endl;
    }

    if(fraction < fraction1){
        cout << "7.Fraction " << fraction1.getNumerator() << "/" << fraction1.getDenominator() << " is bigger." << endl;
    }

    return 0;
}