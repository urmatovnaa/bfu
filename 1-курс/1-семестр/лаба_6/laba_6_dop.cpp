#include <iostream>
#include <fstream>
#include <string>

using namespace std;

    // 1. Файл (cod.txt) содержит закодированные слова вида «2н 3р 1а» в расшифрованном виде это «нн ррр а». 
    // Написать программу, которая может кодировать/декодировать такие файлы. 
    // Результат выполнения должен быть записан в этом же файле.
    // 2. В текстовом файле записан русский текст. Найти в тексте слова, содержащие две одинаковые буквы подряд, 
    // записать их в верхнем регистре и указать после каждого такого слова в скобках найденные буквы. 
    // Полученный текст записать в тот же файл. Весь текст, кроме найденных слов, должен остаться неизменным, \
    // включая и знаки препинания.

unsigned char my_upper(unsigned char s){
    if (s == 184){
        s = char(168);
    }
    else if (s > 223 and s < 256){
        s -= 32;
    }
    return s;
}


int main(){
    setlocale(0, "RU");

    // 2 доп
    ifstream text_2("text2.txt");
    if (!text_2.is_open()) {
        cout << "Ошибка открытия файлов!" << endl;
        return -1;
    }

    string final_text;
    string word;
    string ch;
    bool flag;
    while (text_2 >> word) {
        flag = false;
        for (int i = 1; i < word.length(); i++)  
            if (my_upper(word[i - 1]) == my_upper(word[i])) {
                cout << word << endl;
                flag = true;
                word[i - 1] = my_upper(word[i - 1]);
                word[i] = my_upper(word[i]);
                ch = tolower(word[i]);
            }
        }
        if (flag) {
            final_text += word + "(" + ch + ch + ") ";
        }
        else {
            final_text += word + " ";
        }
    
    text_2.close();

    ofstream output("text2.txt");
    output << final_text;
    output.close();

}
