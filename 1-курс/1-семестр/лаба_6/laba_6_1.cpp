#include <iostream>
#include <cstring> 


/*Лабораторная работа № 6
«Символы и строки»*/

/*Вариант 5
    1. Дана строка длиной не более 100 символов. Найти в ней наиболее часто встречающуюся букву и сделать их заглавными. 
    Регистр не учитывать. Другие символы изменять не нужно.*/


int main(){
    setlocale(LC_ALL, "Rus");

    unsigned char str[100] = "КиЛлуа Золдик";

    int most_count = 0;
    unsigned char most_letter;

    // Длина строки
    int len = 0;
    while (str[len] != '\0')
        len++;

    unsigned char str_2[100];

    // создаем новую строку без заглавных букв

    for (int i=0; i < len; i++){
        if (str[i] == 168){
            str_2[i] = 184; 
        }
        else if (str[i] > 191 and str[i] < 224){
            str_2[i] = str[i] + 32;
        }
        else{
            str_2[i] = str[i];
        }
    }
    
    // Найти в ней наиболее часто встречающуюся букву
    for (int i=0; i < len; i++){          
        int counter = 1;
        for (int j=1; j < len; j++){
            if (str_2[i] == str_2[j]){
                counter += 1;
            }
        if (counter > most_count){
            most_count = counter;
            most_letter = str_2[i];
        }
        }
    }

    // Заменяем наиболее часто встречающуюся букву на заглавный

    for (int i = 0; i<len;i++){
        if (str[i] == most_letter){
            if (str[i] == 184){
                str[i] = 168; 
            }
            else {
                str[i] = str[i] - 32;
            }
        }
    }
    std::cout << str << std::endl;

    // таблица «символ – код»
    std::cout << "таблица «символ – код»" << std::endl;

    for (int i = 33; i < 47; i++) {
        std::cout << char(i) << " " << i << std::endl;
    }
    for (int i = 192; i < 256; i++) {
        std::cout << char(i) << " " << i << std::endl;
        if (i == 197) {
            std::cout << char(168) << " " << 168 << std::endl;
        }
        if (i == 229) {
            std::cout << char(184) << " " << 184 << std::endl;
        }
    }

    return 0;
}