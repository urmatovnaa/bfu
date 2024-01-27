#include <iostream>

int main() {
    const int size = 3; // Размер квадратной матрицы

    // Инициализация квадратной матрицы
    int matrix[size][size] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    // Сумма элементов главной диагонали
    int sumMainDiagonal = 0;
    for (int i = 0; i < size; ++i) {
        sumMainDiagonal += matrix[i][i];
    }

    // Сумма элементов побочной диагонали
    int sumSecondaryDiagonal = 0;
    for (int i = 0; i < size; ++i) {
        sumSecondaryDiagonal += matrix[i][size - 1 - i];
    }

    // Вывод результатов
    std::cout << "Сумма элементов главной диагонали: " << sumMainDiagonal << std::endl;
    std::cout << "Сумма элементов побочной диагонали: " << sumSecondaryDiagonal << std::endl;

    return 0;
}
