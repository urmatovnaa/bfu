#include <cmath>
#include <iostream>

/*Лабораторная работа № 5
«Массивы»*/

/*Доп.
    1. Упорядочить пункт 1 по возрастанию суммы цифр.
    2. Пункт 1 с условием: Если есть три числа с одинаковой суммой цифр.
    3. Проверить является ли введенное число простым. Если нет – вывести все делители.*/

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
    //             int Y = numbers[j];
    //             int sum_digit_Y = 0;
    //             while (Y != 0){        // Находим сумму цифр второго числа
    //                 sum_digit_Y += Y % 10;
    //                 Y /= 10;
    //             }
    //             int X = numbers[i];
    //             int sum_digit_X = 0;
    //             while (X != 0){           // находим сумму цифр первого числа
    //                 sum_digit_X += X % 10;
    //                 X /= 10;
    //             }
    //             if (sum_digit_X < sum_digit_Y){
    //                 int number = numbers[i];
    //                 numbers[i] = numbers[j];
    //                 numbers[j] = number;
    //             }
    //              }
    //     }
    // }
    // for (int n:numbers){
    //     std::cout << n << "\t";
    // }


    // 2

    // int K;
    // std::cin >> K;
    // int count_25 = 0;
    // int numbers[K];
    // bool checking_sim = false;

    // for (int i = 0; i < K; i++) {
    //     std::cin >> numbers[i];
    //     if (numbers[i] == 25){          // Проверяем количество 25 
    //         count_25 += 1;
    //     }
    // }
    // for (int i = 0; i < K; i++){
    //     int similar_sum = 1;
    //     int X = numbers[i];
    //         int sum_digit_X = 0;
    //         while (X != 0){           // находим сумму цифр первого числа
    //             sum_digit_X += X % 10;
    //             X /= 10;
    //         }
    //     for (int j = i+1; j < K; j++){
    //         int Y = numbers[j];
    //         int sum_digit_Y = 0;
    //         while (Y != 0){        // Находим сумму цифр второго числа
    //             sum_digit_Y += Y % 10;
    //             Y /= 10;
    //         }
    //         if (sum_digit_X == sum_digit_Y){
    //             similar_sum += 1; 
    //         }
    //         }
    //     if (similar_sum == 3){
    //         checking_sim = true;
    //     }
    //     }
    // if (checking_sim){
    //     for (int i = 0; i < K; i++){
    //         for (int j = 0; j < K; j++){
    //             int Y = numbers[j];
    //             int sum_digit_Y = 0;
    //             while (Y != 0){        // Находим сумму цифр второго числа
    //                 sum_digit_Y += Y % 10;
    //                 Y /= 10;
    //             }
    //             int X = numbers[i];
    //             int sum_digit_X = 0;
    //             while (X != 0){           // находим сумму цифр первого числа
    //                 sum_digit_X += X % 10;
    //                 X /= 10;
    //             }
    //             if (sum_digit_X < sum_digit_Y){
    //                 int number = numbers[i];
    //                 numbers[i] = numbers[j];
    //                 numbers[j] = number;
    //             }
    //              }
    //     }
    // }

    // for (int n:numbers){
    //     std::cout << n << "\t";
    // }

    // 3

    int K;
    std::cin >> K;
    bool prime_is = true;
    int div[100];
    int counter = 1;
    div[0] = 1;
    if (K > 1){
        for (int i = 2; i <= K / 2; i++){
            if (K % i == 0){
                prime_is = false;
                div[counter] = i;
                counter += 1;
            }          
        }
        div[counter] = K;
    }
    if (! prime_is){
        for (int i = 0; i <= counter; i++){
            std::cout << div[i] << "\t";
            }       
        }       
    else{
        std::cout << "PRIME\n";
    }

    return 0;
}
