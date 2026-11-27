#ifndef OOP_COMPLEX_H_INCLUDED
#define OOP_COMPLEX_H_INCLUDED

#include <iostream>

class Complex
{
private:
    double real_;
    double imag_;

public:
    Complex();
    Complex(double real_, double imag_ = 0.0);
    Complex(const Complex &number);

    Complex& operator=(const Complex &number);

    bool operator==(const Complex &number) const;
    bool operator!=(const Complex &number) const;

    Complex operator+() const;
    Complex operator-() const;

    Complex operator+(const Complex &number) const;
    Complex operator-(const Complex &number) const;
    Complex operator*(const Complex &number) const;
    Complex operator/(const Complex &number) const;

    Complex operator+(double scalar) const;
    Complex operator-(double scalar) const;
    Complex operator*(double scalar) const;
    Complex operator/(double scalar) const;

    Complex& operator+=(const Complex &number);
    Complex& operator-=(const Complex &number);
    Complex& operator*=(const Complex &number);
    Complex& operator/=(const Complex &number);

    Complex& operator+=(double scalar);
    Complex& operator-=(double scalar);
    Complex& operator*=(double scalar);
    Complex& operator/=(double scalar);

    friend std::ostream& operator<<(std::ostream &stream, const Complex &number);
    friend std::istream& operator>>(std::istream &stream, Complex &number);

    double Real() const;
    double Imag() const;
    Complex& Real(double real);
    Complex& Imag(double imag);
    double Abs() const;
};

#endif // OOP_COMPLEX_H_INCLUDED
