#include <ostream>

class Fraction{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 0) :
    numerator(numerator), denominator(denominator) {
        reduce();
    };

    ~Fraction(){
         std::cout << numerator << "/" << denominator << " ";
        numerator = 0;
        denominator = 0;
        std::cout << "You destroid all tnat i done!" << std::endl;
    };

    int getNumerator() const;
    int getDenominator() const;
    void setNumerator(int numerator);
    void setDenominator(int denominator);

    void reduce();
    void reduce(Fraction &frac);
    friend void lmc(Fraction &A, Fraction &B);

    Fraction operator + (Fraction& b);
    void operator = (Fraction& A);

    bool operator == (const Fraction &rhs) const;
    bool operator != (const Fraction &rhs) const;

    friend std::ostream &operator << (std::ostream &os, const Fraction &fraction);
    friend std::istream &operator >> (std::istream &is, Fraction &fraction);

    bool operator < (Fraction &B);
    bool operator > (Fraction &B);

};
