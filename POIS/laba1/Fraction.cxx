// Fraction.cpp
module;
#include <iostream>
#include <numeric>
#include <stdexcept>
#include <cmath> // Для abs

export module Fraction; // Объявляем модуль

class Sign {
private:
    char visual;

public:
    Sign() : visual('+') {}

    Sign(const char& v) : visual(v) {
        if (v != '+' && v != '-') {
            visual = '+'; 
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Sign& sign) {
        os << sign.visual; 
        return os;
    }

    int operator*(int number) const {
        return (visual == '+' ? number : -number);
    }

    friend class Fraction;
};

export class Fraction {
private:
    Sign sign;  
    int up;  
    int down;  

    void simplify() {
        int gcd_value = std::gcd(std::abs(up), std::abs(down));  
        up /= gcd_value;  
        down /= gcd_value;  

        if (down < 0) {  
            down = -down;  
            up = -up;  
        }
    }

public:  
    Fraction() : sign('+'), up(0), down(1) {}

    Fraction(Sign sign, int up, int down) : sign(sign) {
        if (down == 0) {  
            throw std::invalid_argument("denominator cannot be equal to zero");  
        }

        this->up = up;  
        this->down = down;  
        simplify();  
    }

    double getDouble() const {
        return static_cast<double>(this->up) / this->down;  
    }

    // Перегрузка оператора +
    Fraction operator+(const Fraction& other) const {  
        int new_up = this->sign * this->up * other.down + other.sign * other.up * this->down;  
        int new_down = this->down * other.down;

        Sign new_sign(new_up < 0 ? '-' : '+');
        return Fraction(new_sign, std::abs(new_up), new_down);  
    }

    Fraction operator+(const int number) const {  
        Sign sign(number < 0 ? '-' : '+');  
        Fraction new_fraction(sign, std::abs(number), 1);  
        return (*this + new_fraction);   
    }

    // Перегрузка оператора -
    Fraction operator-(const Fraction& other) const {
        Sign new_sign(other.sign.visual == '+' ? '-' : '+'); 
        return *this + Fraction(new_sign, other.up, other.down); 
    }

    // Перегрузка оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Fraction& fraction) {
        os << fraction.sign << fraction.up << "/" << fraction.down; 
        return os;
    }
};
