#include "oop_complex.h"
#include <cmath>

Complex::Complex() : real_(0.0), imag_(0.0) {}
Complex::Complex(double real, double imag) : real_(real), imag_(imag) {}
Complex::Complex(const Complex &number) : real_(number.real_), imag_(number.imag_) {}

Complex& Complex::operator=(const Complex &number)
{
    if (this != &number)
    {
        real_ = number.real_;
        imag_ = number.imag_;
    }
    return *this;
}

bool Complex::operator==(const Complex &number) const
{
    return (real_ == number.real_) && (imag_ == number.imag_);
}

bool Complex::operator!=(const Complex &number) const
{
    return !(*this == number);
}

Complex Complex::operator+() const
{
    return *this;
}

Complex Complex::operator-() const
{
    return Complex(-real_, -imag_);
}

Complex Complex::operator+(const Complex &number) const
{
    return Complex(real_ + number.real_, imag_ + number.imag_);
}

Complex Complex::operator-(const Complex &number) const
{
    return Complex(real_ - number.real_, imag_ - number.imag_);
}

Complex Complex::operator*(const Complex &number) const
{
    double new_real = real_ * number.real_ - imag_ * number.imag_;
    double new_imag = real_ * number.imag_ + imag_ * number.real_;
    return Complex(new_real, new_imag);
}

Complex Complex::operator/(const Complex &number) const
{
    double del = number.real_ * number.real_ + number.imag_ * number.imag_;
    double new_real = real_ * number.real_ + imag_ * number.imag_;
    double new_imag = imag_ * number.real_ - real_ * number.imag_;
    if (del != 0)
    {
        return Complex(new_real / del, new_imag / del);
    }
    return 0.0;
}

Complex Complex::operator+(double scalar) const
{
    return Complex(real_ + scalar, imag_);
}

Complex Complex::operator-(double scalar) const
{
    return Complex(real_ - scalar, imag_);
}

Complex Complex::operator*(double scalar) const
{
    return Complex(real_ * scalar, imag_ * scalar);
}

Complex Complex::operator/(double scalar) const
{
    return Complex(real_ / scalar, imag_ / scalar);
}

Complex& Complex::operator+=(const Complex &number)
{
    *this = *this + number;
    return *this;
}

Complex& Complex::operator-=(const Complex &number)
{
    *this = *this - number;
    return *this;
}

Complex& Complex::operator*=(const Complex &number)
{
    *this = *this * number;
    return *this;
}

Complex& Complex::operator/=(const Complex &number)
{
    *this = *this / number;
    return *this;
}

Complex& Complex::operator+=(double scalar)
{
    *this = *this + scalar;
    return *this;
}

Complex& Complex::operator-=(double scalar)
{
    *this = *this - scalar;
    return *this;
}

Complex& Complex::operator*=(double scalar)
{
    *this = *this * scalar;
    return *this;
}

Complex& Complex::operator/=(double scalar)
{
    *this = *this / scalar;
    return *this;
}

std::ostream& operator<<(std::ostream &stream, const Complex &number)
{
    if (number.imag_ >= 0)
        stream << number.real_ << " + " << number.imag_ << "i";
    else
        stream << number.real_ << " - " << -number.imag_ << "i";
    return stream;
}

std::istream& operator>>(std::istream &stream, Complex &number)
{
    stream >> number.real_ >> number.imag_;
    return stream;
}

double Complex::Real() const
{
    return real_;
}

double Complex::Imag() const
{
    return imag_;
}

Complex& Complex::Real(double real)
{
    real_ = real;
    return *this;
}

Complex& Complex::Imag(double imag)
{
    imag_ = imag;
    return *this;
}

double Complex::Abs() const
{
    return std::sqrt(real_ * real_ + imag_ * imag_);
}
