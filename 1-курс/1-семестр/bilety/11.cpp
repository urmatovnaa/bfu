#include <iostream>
#include <fstream>

int main() {
    // Открытие файла на чтение
    std::ifstream inputFile("example.txt");

    // Проверка, удалось ли открыть файл
    if (!inputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Считывание данных из файла
    std::string data;
    while (std::getline(inputFile, data)) {
        std::cout << "Прочитано из файла: " << data << std::endl;
    }

    // Закрытие файла
    inputFile.close();

    // Открытие файла на запись
    std::ofstream outputFile("output.txt");

    // Проверка, удалось ли открыть файл
    if (!outputFile.is_open()) {
        std::cerr << "Не удалось открыть файл для записи." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Запись данных в файл
    outputFile << "Пример записи в файл." << std::endl;
    outputFile << "Вторая строка записи в файл." << std::endl;

    // Закрытие файла
    outputFile.close();


    // Открытие файла на чтение и запись
    std::fstream file("example.txt", std::ios::in | std::ios::out);

    // Проверка, удалось ли открыть файл
    if (!file.is_open()) {
        std::cerr << "Не удалось открыть файл для чтения и записи." << std::endl;
        return 1; // Возвращаем код ошибки
    }

    // Считывание и вывод данных из файла
    std::string data;
    while (std::getline(file, data)) {
        std::cout << "Прочитано из файла: " << data << std::endl;
    }

    // Запись данных в файл
    file << "Новая строка записи в файл." << std::endl;

    // Закрытие файла
    file.close();

    return 0;
}


    return 0;
}
