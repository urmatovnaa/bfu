#include <cmath>
#include <iostream>
#include <typeinfo>


//Вариант 5    

int main() {
    // Основная лаба
    /*1. Если A+B кратно C и C кратно B, то вывести (A+B)/C-C/B, 
      если A+B кратно C и C не кратно B, то вывести (A+B)/С+B*C,
      в остальных случаях вывести A-B+C.*/

    int A, B, C;
    std::cin >> A >> B >> C;

    if (A < 0 or B < 0 or C < 0) {
      std::cout << "НАТУРАЛЬНЫЕ ЧИСЛА";
    }
    else if ((A + B) % C == 0 and C != 0) {
      int result = (A + B) / C + B * C;
      std::cout << "(A + B) % C == 0 and C % B != 0, " << result << std::endl;
    } 
    else if ((A + B) % C == 0 and C % B == 0 and B != 0 and C!= 0){
      int result = (A + B) / C - C / B;
      std::cout << "(A + B) % C == 0 and C % B == 0, " << result << std::endl;
    } 
    else {
      int result = A-B+C;
      std::cout << "(A + B) % C != 0, " << result << std::endl;
    }

    // 2. Ввести число N, которое обозначает некоторую ошибку (см пример). Расшифровать её.

    int N;
    std::cin >> N;
    switch (N){
      case 1:
        std::cout << "Ошибка чтения файла" << std::endl;
        break;
      case 25:
        std::cout << "Ошибка записи файла" << std::endl;
        break;
      case 3:
        std::cout << "Поля не определены" << std::endl;
        break;
      case 404:
        std::cout << "Страница не найдена" << std::endl;
        break;
      case 508:
        std::cout << "Плохое соединение" << std::endl;
        break; 
      case 1101:
        std::cout << "Просто не получилось" << std::endl;
        break;
      default:
        std::cout << "Такой ошибки нет!!!!!!!" << std::endl;
        break;
    }
    /*Доп.Переменная X может принимать 2 значения: -1 и 1. 
    Если -1, то вывести в консоль “Negative number”, если положительное - “Positive number”.
    */
    // 1-вариант
    int X;
    std::cin >> X;
    std::cout << (X==1) ? "Positive number": "Negative number"; 

    return 0;

}

