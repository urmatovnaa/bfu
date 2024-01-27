#include <iostream>

int main() {
    // Пример синтаксиса
    int operand1 = 5;    // Бинарное представление: 0101
    int operand2 = 3;    // Бинарное представление: 0011

    int result = operand1 & operand2; // Бинарное И: 0001

    // Вывод результата
    std::cout << "Результат операции И: " << result << std::endl;

    int result2 = operand1 | operand2; // Бинарное ИЛИ: 0111

    // Вывод результата
    std::cout << "Результат операции ИЛИ: " << result2 << std::endl;


    return 0;
}
