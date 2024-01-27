#include <iostream>
#include <cctype> // Для использования функции tolower

int main() {
    std::string inputString;
    
    // Ввод строки
    std::cout << "Введите строку: ";
    std::getline(std::cin, inputString);

    char targetChar = 'x'; // Искомый символ

    // Преобразование символа в нижний регистр (регистр не важен)
    char targetCharLower = std::tolower(targetChar);

    // Индекс текущего символа в строке
    int index = 0;

    // Поиск первого вхождения символа
    while (index < inputString.length() && std::tolower(inputString[index]) != targetCharLower) {
        index++;
    }

    // Проверка, был ли найден символ
    if (index < inputString.length()) {
        std::cout << "Первое вхождение символа '" << targetChar << "' в позиции " << index + 1 << std::endl;
    } else {
        std::cout << "Символ '" << targetChar << "' не найден в строке." << std::endl;
    }

    return 0;
}
