#include <iostream>

int main() {
    // Пример синтаксиса
    int number1, number2;

    // Ввод чисел
    std::cout << "Введите первое число: ";
    std::cin >> number1;

    std::cout << "Введите второе число: ";
    std::cin >> number2;

    // Проверка условия и вывод максимального числа
    if (number1 > number2) {
        std::cout << "Максимальное число: " << number1 << std::endl;
    } else {
        std::cout << "Максимальное число: " << number2 << std::endl;
    }

    return 0;
}
