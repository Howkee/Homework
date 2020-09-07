#include <regex>
#include <iostream>
#include "fraction.h"

int Fraction::getNumerator() const {
    return numerator;
}
int Fraction::getDenominator() const {
    return denominator;
}
void Fraction::setNumerator(int numerator) {
    Fraction::numerator = numerator;
}
void Fraction::setDenominator(int denominator) {
    Fraction::denominator = denominator;
}

void Fraction::reduce(Fraction &frac){
    int dil = std::__gcd(frac.numerator, frac.denominator);
    frac.numerator /= dil;
    frac.denominator /= dil;
}
void Fraction::reduce(){
    int dil = std::__gcd(numerator, denominator);
    numerator /= dil;
    denominator /= dil;
}

std::ostream &operator << (std::ostream &os, const Fraction &fraction) {
    os << "Fraction: " << fraction.numerator << "/" << fraction.denominator;
    return os;
}

std::istream &operator >> (std::istream &is, Fraction &fraction){
    cout >> "Enter numerator";
    is >> fraction.numerator;
    cout >> "Enter denominator";
    is >> fraction.denominator;
    return is;
}

void Fraction::operator = (Fraction& A){
    reduce(A);
    this->numerator = A.numerator;
    this->denominator = A.denominator;
}


bool Fraction::operator == (const Fraction &rhs) const {
    return (this->numerator == rhs.numerator) &&
           (this->denominator == rhs.denominator);
}
bool Fraction::operator != (const Fraction &rhs) const {
    return ( (rhs.numerator != numerator) || (rhs.denominator != denominator) );
}

//зведення до спільного знаменника
void lmc(Fraction &A, Fraction &B){
    // шукаємо LMC
    int temp = (A.denominator*B.denominator)/(std::__gcd(A.denominator,B.denominator));
    A.numerator *= (temp/A.denominator);
    A.denominator *= (temp/A.denominator);
    B.numerator *= (temp/B.denominator);
    B.denominator *= (temp/B.denominator);
}

/******************************************************************/

Fraction Fraction :: operator + (Fraction &B) {
    Fraction A = *this;
    if(this->denominator != B.denominator)
        lmc(A,B);
    return Fraction(this->numerator + B.numerator, B.denominator);
}

bool Fraction :: operator < (Fraction &B) {
    Fraction A = *this;
    if(this->denominator != B.denominator)
        lmc(A,B);
    if(A.numerator > B.numerator)
        return true;
    else
        return false;
}

bool Fraction::operator > (Fraction &B) {
    Fraction A = *this;
    if(this->denominator != B.denominator)
        lmc(A,B);
    if(A.numerator > B.numerator)
        return false;
    else
        return true;
}

