#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imaginary;

public:
    Complex() : real(0.0), imaginary(0.0) {}

    void setComplex(double r, double i) {
        real = r;
        imaginary = i;
    }

    void printComplex() const {
        cout << real;
        if (imaginary >= 0) {
            cout << " + " << imaginary << "i";
        } else {
            cout << " - " << -imaginary << "i";
        }
        cout << endl;
    }

    Complex operator+(const Complex& obj) const {
        Complex result;
        result.real = real + obj.real;
        result.imaginary = imaginary + obj.imaginary;
        return result;
    }

    Complex operator*(const Complex& obj) const {
        Complex result;
        result.real = (real * obj.real) - (imaginary * obj.imaginary);
        result.imaginary = (real * obj.imaginary) + (imaginary * obj.real);
        return result;
    }

    Complex operator-(const Complex& obj) const {
        Complex result;
        result.real = real - obj.real;
        result.imaginary = imaginary - obj.imaginary;
        return result;
    }

    Complex operator/(const Complex& obj) const {
        Complex result;
        double denominator = (obj.real * obj.real) + (obj.imaginary * obj.imaginary);
        result.real = ((real * obj.real) + (imaginary * obj.imaginary)) / denominator;
        result.imaginary = ((imaginary * obj.real) - (real * obj.imaginary)) / denominator;
        return result;
    }
};
