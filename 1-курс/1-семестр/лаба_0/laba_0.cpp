/* Задать целые значения N и M рандомно из диапазона [3;3+K], 
где K – номер варианта. И определить нецелочисленную матрицу А[N][M]. 
Все значения матрицы кроме главного и побочного пояса* заполнить числами 
из диапазона (-0,1;0,1) \ {0} ** с 3-мя знаками после запятой. 
В ячейках главного пояса указать свой вариант, в ячейках побочного – минус вариант, 
в пересечении нули. Для заполнения использовать одну функцию, 
которая возвращает после заполнения строку вида «Аа» 
где символ соответствует букве из алфавита с номером К+5 
(Например для варианта 1 это строка «Ее»). 
Добавить в программу процедуру вывода матрицы на экран. 
Полученную строку записать в файл out.txt */


#include <iostream>
#include <ctime>
#include <string>
#include <fstream>

using namespace std;


string simple(float** A, int N, int M, int K) {
    for (int i = 0; i < N; i++)
        if (N % 2 == 0)
            if ((i == N / 2) or (i == N / 2 - 1))
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) or (j == M / 2 - 1))
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
                    else
                        if (j == M / 2)
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
            else
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) or (j == M / 2 - 1))
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 199 - 99) * 0.001;
                    else
                        if (j == M / 2)
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 199 - 99) * 0.001;
        else
            if (i == N / 2)
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) || (j == M / 2 - 1))
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
                    else
                        if (j == M / 2)
                            A[i][j] = 0;
                        else
                            A[i][j] = K;
            else
                for (int j = 0; j < M; j++)
                    if (M % 2 == 0)
                        if ((j == M / 2) or (j == M / 2 - 1))
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 199 - 99) * 0.001;
                    else
                        if (j == M / 2)
                            A[i][j] = -K;
                        else
                            A[i][j] = (rand() % 199 - 99) * 0.001;
    string ABC = "АБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ";
    string s = "";
    s += ABC[K + 4];
    s += tolower(ABC[K + 4]);
    return s;
}

void show_matrix(float** A, int N, int M) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << "\n";
    }
}

int main(){

    setlocale(LC_ALL, "Rus");
    srand((unsigned int)time(0));
    int K = 5;
    int N = rand() % (K + 1) + 3;
    int M = rand() % (K + 1) + 3;
    float** A;
    A = new float* [N];
    for (int i = 0; i < N; ++i) {
        A[i] = new float[M];
    }
    ofstream file("out.txt");
    if (!file.is_open())
        cout << "Файл не открыт" << endl;
    else {
        string result =  simple(A, N, M, K);
        file << result;
        cout << result << endl;
        file.close();
    }
    show_matrix(A, N, M);

    for (int i = 0; i < N; i++)
        delete[] A[i];
    delete[] A;
    return 0;
}