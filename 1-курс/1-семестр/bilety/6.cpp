#include <iostream>

int main() {
    // Пример синтаксиса
    int subjectCode;

    // Ввод кода предмета
    std::cout << "Введите код предмета: ";
    std::cin >> subjectCode;

    // Оператор выбора switch...case
    switch (subjectCode) {
        case 1:
            std::cout << "Математика" << std::endl;
            break;
        case 2:
            std::cout << "Физика" << std::endl;
            break;
        case 3:
            std::cout << "Химия" << std::endl;
            break;
        case 4:
            std::cout << "Информатика" << std::endl;
            break;
        default:
            std::cout << "Неизвестный предмет" << std::endl;
            break;
    }

    return 0;
}
