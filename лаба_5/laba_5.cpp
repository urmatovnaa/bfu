#include <cmath>
#include <iostream>

/*Лабораторная работа № 5
«Массивы»

Длина последовательности K вводится с клавиатуры (K <20).
В пункте 1 считать, что числа вводятся корректно.
Размеры матрицы M x N (N <10, M <10). N – кол-во столбцов, M – кол-во строк.
Считать, что число однозначные числа, такие как 3 или 5, не удовлетворяют условию «все цифры числа одинаковы».*/

/*Вариант 5
    1. Дана последовательность натуральных чисел {A1, A2, …, AK}. 
    Упорядочить её по возрастанию, если число 25 встречается больше двух раз.
    2. Ввести размеры и заполнить матрицу T [M x N] целыми числами. 
    Найти строку с наибольшим кол-вом нулей и заменить их на 888.*/


//1
int main() {
    // 1

    // int K;
    // std::cin >> K;
    // int count_25 = 0;
    // int numbers[K];

    // for (int i = 0; i < K; i++) {
    //     std::cin >> numbers[i];
    // if (numbers[i] == 25){          // Проверяем количество 25 
    //         count_25 += 1;
    //     }
    // }
    // if (count_25 > 2){
    //     for (int i = 0; i < K; i++){
    //         for (int j = 0; j < K; j++){
    //             if (numbers[i] < numbers[j]){
    //                 int number = numbers[i];
    //                 numbers[i] = numbers[j];
    //                 numbers[j] = number;
    //             }
    //         }
    //     }
    // }
    // for (int n:numbers){
    //     std::cout << n << "\t";
    // }


    // 2

    unsigned short N, M;    // N-кол-во столбцов, M – кол-во строк
    std::cout << "Кол-во столбцов:";
    std::cin >> N;
    std::cout << "Кол-во строк:";
    std::cin >> M;
    int matrix[M][N];
    int check[2];
    check[1] = 0;
    check[0] = 22; 

    for (int i=0; i<M; i++){           // Заполняем матрицу 
        int counter = 0;
        for (int j=0; j<N; j++){
            std::cin >> matrix[i][j];
            if (matrix[i][j] == 0){
                counter += 1;
            }
        if (counter > check[1]){         // Hаходим строку с наибольшим кол-вом нулей
            check[1] = counter;
            check[0] = i;
        }
    }
    }
    int i = check[0];
    if (i < 10){
        for (int j=0; j<N; j++){
            if (matrix[i][j] == 0){          // Заменяем 0 на 888
                matrix[i][j] = 888;
            }
        }
    }
    for (int i=0; i<M; i++){
        for (int j=0; j<N; j++){
            std::cout << matrix[i][j] << ' ';      // Выводим все 
        }
        std::cout << std::endl;
    }
    
    return 0;

}