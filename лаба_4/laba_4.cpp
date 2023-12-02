#include <cmath>
#include <iostream>


//Вариант 5    

int main() {
    std::cout << 1/10;
    // Основная лаба
    /*1. Дана последовательность вещественных чисел {A1, A2, …, AN}. Найти сумму всех чисел, не превышающих 50.12, наименьшее из таких чисел и его номер в последовательности.
    2. Дано целое число X <10.000. Найти есть ли в его записи цифра 3, если есть вывести последний индекс. */
    int quantity;
    std::cin >> quantity;
    double summa = 0;
    double minimum;
    int min_index;
    int S_AI = 0;  // 1-доп

    for (int i = 0; i < quantity; i++) {
        double number;
        std::cin >> number;
        if (number <= 50.12){     // Находим сумму 
            summa += number;
        }

        if (i == 0 or minimum > number){ // Находим минимум
            minimum = number;
            min_index = i;
        }
        if (i % 2){            // 1- доп S(AI)
            S_AI += number;
        }
        else {
            S_AI -= number;
        } 
    }

    std::cout << "Сумма чисел = " << summa << std::endl; 
    if (summa > 0){
        std::cout << "Минимальное число = " << minimum << " и его индекс = " << min_index << std::endl;
    }
    std::cout << "S(AI) = " << S_AI << std::endl;
    // 2
    int X;
    std::cin >> X;
    bool has_3 = false;
    int last_index = 0;
    while (X != 0){
        if (abs(X % 10) == 3){
            has_3 = true;
        }
        X /= 10;
        last_index += 1;
    }
    if (has_3){
        std::cout << last_index - 1 << std::endl;
    }
   


    return 0;

}


