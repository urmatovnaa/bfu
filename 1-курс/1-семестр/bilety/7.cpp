#include <iostream>

int main() {
    const int size1 = 5;
    const int size2 = 7;

    int array1[size1] = {1, 2, 3, 4, 5};
    int array2[size2] = {3, 5, 7, 9, 11, 13, 15};

    // Флаг для проверки наличия элементов из array1 в array2
    bool found = false;

    // Проверка наличия элементов из array1 в array2
    for (int i = 0; i < size1; ++i) {
        for (int j = 0; j < size2; ++j) {
            if (array1[i] == array2[j]) {
                found = true;
                break; // Если элемент найден, выходим из внутреннего цикла
            }
        }

        // Если элемент не найден, выводим сообщение
        if (!found) {
            std::cout << "Элемент " << array1[i] << " из array1 не найден в array2." << std::endl;
        }

        // Сбрасываем флаг перед проверкой следующего элемента
        found = false;
    }

    return 0;
}
