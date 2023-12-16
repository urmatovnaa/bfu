#include <iostream>

using namespace std;


int matrix_norm(int **matrix, int n, int m) {
	int maxsum = 0;
    int sum = 0;
    for (int j = 0; j < m; j++) {
        sum = 0;
        for (int i = 0; i < n; i++)
            sum += abs(matrix[i][j]);
        if (sum > maxsum)
            maxsum = sum;
    }
	return maxsum;
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
}



int main()
{
    setlocale(0, "");

    cout << "1-пункт" << endl;

    int K, S, var;
    int* A;
    bool flag;
    cout << "Введите номер варианта: ";
    cin >> var;
    
    if (var < 4 or var > 6) {
        var = 5;
    }
    cout << "Введите размер массива K: ";
    cin >> K;
    if (K < 0){
        return -1;
    }
    A = (int*)malloc(K * sizeof(int));
    for (int i = 0; i < K; i++) {
        A[i] = i;
        cout << A[i] << " ";
    }

    cout << "Введите S: ";
    cin >> S;

    if (S + K < 0){
        return -2;
    }

    A = (int*)realloc(A, (K + S) * sizeof(int));
    if (S < 0) {
        cout << "Массив урезан: ";
        for (int i = 0; i < K + S; i++)
            cout << A[i] << " ";
    }
    else {
        cout << "Введите элементы матрицы: \n";
        for (int i = 0; i < K; i++)
            cout << A[i] << " ";
        for (int i = K; i < K + S; i++)
            cin >> A[i];

        switch (var)
        {
        case 4:
        {
            int index;
            int max = 0;
            for (int i = K; i < K + S; i++){
                if (A[i] > max) {
                    max = A[i];
                    index = i;
                }
            }
            if (max % 2 == 1){
                A[index] *= 100;
            }
            break;
        }
        case 5:
        {
            int count_1 = 0;
            int count_0 = 0;
            for (int i = K; i < K + S; i++)
                if (A[i] % 2)
                    count_1++;
                else
                    count_0++;
            if (count_0 > count_1)
                for (int i = 0; i < K + S; i++)
                    A[i]++;
            break;
        }
        case 6:
        {
            for (int i = K; i < K + S; i++)
                if (A[i] < 0) {
                    for (int j = K; j < K + S; j++)
                        A[j] += 5;
                    break;
                }
            break;
        }
        default:
            break;
        }
        for (int i = 0; i < K + S; i++)
            cout << A[i] << " ";
    }
    free(A);

    cout << "\n2-пункт" << endl;
    int N, M;
    cout << "Введите размеры матрицы N x M: ";
    cin >> N;
    cin >> M;

    int** AA = new int* [N];
    for (int i = 0; i < N; ++i)
        AA[i] = new int[M];

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            AA[i][j] = 10*(i + 1) + j + 1;
        }
    }

    cout << "Исходная матрица: \n";
    output(AA, N, M);

    //матричная норма 
    int norm_1 = matrix_norm(AA, N, M);

    cout << "Матричная норма исходной матрицы = " << norm_1 << endl;

    //транспонирование
    int** B = new int* [M];
    for (int i = 0; i < M; i++)
        B[i] = new int[N];

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            B[i][j] = AA[j][i];
        }
    }

    cout << "Транспонированная матрица: \n";
    output(B, M, N);

    // матричная норма 2-матрицы
    int norm_2 = matrix_norm(B, M, N);
    cout << "Матричная норма транспонированной матрицы = " << norm_2 << endl;

    if (norm_2 > norm_1)
        cout << "Норма транспонированной матрицы больше исходной";
    else if (norm_1 > norm_2)
        cout << "Норма исходной матрицы больше транспонированной";
    else
        cout << "Нормы равны";

    for (int i = 0; i < N; i++)
        delete[] AA[i];
    delete[] AA;
    for (int i = 0; i < M; i++)
        delete[] B[i];
    delete[] B;
    return 0;
}