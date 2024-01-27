#include <iostream>

int main() {
    // Пример синтаксиса
    int operand1 = 5;     // Бинарное представление: 0101
    int operand2 = 3;    // Бинарное представление: 0011


    int result = ~operand1; // Бинарная операция НЕ: 1010

    // Вывод результата
    std::cout << "Результат операции НЕ: " << result << std::endl;

    int result2 = operand1 ^ operand2; // Бинарное Исключающее ИЛИ: 0110

    // Вывод результата
    std::cout << "Результат операции Исключающее ИЛИ: " << result2 << std::endl;


    return 0;
}
