#include <iostream>
#include <cmath>

int main() {
    double base = 2.0;
    double exponent = 3.0;

    double result = std::pow(base, exponent);

    std::cout << base << " в степени " << exponent << " равно " << result << std::endl;

    double number = 64.0;
    
    double squareRoot = std::sqrt(number);

    std::cout << "Корень из " << number << " равен " << squareRoot << std::endl;

    double angleInRadians = 30; // Например, угол 1 радиан

    double sinValue = std::sin(angleInRadians);

    std::cout << "Синус угла " << angleInRadians << " равен " << sinValue << std::endl;


    return 0;
}
