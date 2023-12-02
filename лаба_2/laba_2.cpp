// Online C++ compiler to run C++ program online
#include <cmath>
#include <iostream>

int main() {
    // Основная лаба

    // int i;
    // std::cin >> i;
    // unsigned char X = 7;
    // 00000111
    // unsigned char X = 20;
    // 00010100
    // unsigned char X = 34;
    // 00100010
    // bool bit = char(1 * pow(2,i))  &  X;
    // std::cout << bit << std::endl;
    
    // 1-доп
    // std::cout << 255 -(X+1) << std::endl;

    // 2-доп Поменять значения i-го и j-го битов местами.
    int i, j;
    std::cin >> i;
    std::cin >> j;
    unsigned char X = 145;
    bool bit_i = char(1 * pow(2,i))  &  X;
    bool bit_j = char(1 * pow(2,j))  &  X;
    int change = X - (bit_i*pow(2,i) + bit_j*pow(2,j)) + (bit_i*pow(2,j) + bit_j*pow(2,i));

    std::cout << change << std::endl;

    // 3-доп

    return 0;

}

