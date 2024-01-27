#include <iostream>

void bubbleSortAscending(int arr[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                // Обмен элементов, если текущий больше следующего
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    const int size = 5;
    int array[size] = {5, 2, 8, 1, 7};

    // Сортировка по возрастанию
    bubbleSortAscending(array, size);

    // Вывод отсортированного массива
    std::cout << "Массив по возрастанию: ";
    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
