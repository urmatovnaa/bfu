#include <iostream>
#include <fstream>
#include <string>



/*2. Дан файл, содержащий русский текст. Найти в тексте N (N ≤ 10) самых длинных слов, не содержащих одинаковых букв. 
    Записать найденные слова в текстовый файл в порядке не возрастания длины. Все найденные слова должны быть разными.*/


std::string wt_punct(std::string s) {
    std::string l = "";
    short len = s.length() - 1;

    if (s == ">>" or s == "<<"){
        return " ";
    }

    while (ispunct(s[len])){
        len--;
    }
    for (int i = 0; i < len + 1; i++){
        char letter = s[i];
        if (not ispunct(letter)){
            l += tolower(s[i]);}
        else{
            if (l.length() > 0){
               l += tolower(s[i]); 
            }
        }
    }
    return l;
}

int main(){
    setlocale(0, "RU");

    //Чтение заданного N
    short N;
    std::ifstream inp("input.txt");

    //В файле input.txt проверяем файл
    if (inp.is_open()){
        inp >> N;
        inp.close();
    }
    else {
        std::cout << "Файл не прочитан." << std::endl;
        std::cout << "Введите N:";
        std::cin >> N;
    }
    if (N < 0 or N > 10) {
        std::cout << "Введён некорректный N ";
        return -1;
    }
    // Получение массива слов

    std::string str_now, s;
    bool in_top; 
    std::string result[10];
    int n = 0;

    std::ifstream text("text.txt");
    if (!text.is_open()) {
        std::cout << "Файл text.txt не открыт";
        return -1;
    }

    while (!text.eof()) {
        text >> s;
        in_top = true;
        

        // убираем все ненужные знаки из слова и меняем заглавные буквы на маленькие 
        str_now = wt_punct(s);

        // проверяем на уникальность букв
        for (int i = 0; i < str_now.length(); i++) {
            for (int j = i + 1; j < str_now.length(); j++) {
                if (str_now[i] == str_now[j]) {
                    in_top = false;
                    break;
                }
            }
            if (!in_top)
                break;     
        }
        // проверяем на дубликаты слова
        for (int t = 0; t < n; t++) {
            if (result[t] == str_now) {
                in_top = false;
                break;
            }
        }
        // сортируем в порядке не возрастания длины
        if (in_top) {
            for (int t = 0; t < 10; t++) {
                if (str_now.length() > result[t].length()) {
                    std::string change = result[t];
                    result[t] = str_now;
                    str_now = change;
                }
            }
            n++;
        }
    }
    std::ofstream file("result.txt");
    for (int i = 0; i < 10; i++) {
        file << result[i] << std::endl;
        std::cout << result[i] << std::endl;
    }
    file.close();
}
