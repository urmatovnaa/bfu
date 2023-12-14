#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

using namespace std;

int matrix[11][11];
int N;

//1 пункт
void get_matrix(string name)
{
	ifstream text(name);
	if (!text.is_open()) {
		cout << "Файл закрыт";
	}
	else {
		text >> N;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				text >> matrix[i][j];
	}
	text.close();
}

void show_matrix()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}
	cout << endl;
}

void write_matrix(string name)
{
	ofstream output(name);
	if (!output.is_open()) {
		cout << "Файл не открыт";
	}
	else {
		output << N << "\n";
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++)
				output << matrix[i][j] << " ";
			output << "\n";
		}
		cout << "Матрица записана" << endl;
	}
	output.close();
}

int min_matrix() {
	int min = matrix[0][0];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] < min) {
				min = matrix[i][j];
			}
		}

	return min;
}

int max_matrix() {
	int max = matrix[0][0];

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (matrix[i][j] > max) {
				max = matrix[i][j];
			}
		}

	return max;
}

bool is_equal(int number1, int number2) {
    int sum_1 = 0;
    int sum_2 = 0;

    while (abs(number1) != 0){
        sum_1 += number1 % 10;
        number1 /= 10;
    }

    while (abs(number2) != 0){
        sum_2 += number2 % 10;
        number2 /= 10;
    }

	return (sum_1 == sum_2);
}

bool is_prime(int number) {
    number = abs(number);
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}


void sort() {
    int summa, summa2;
	for (int i = 0; i < N; i++){
		for (int j = i + 1; j < N; j++){
			summa2 = 0;
			summa = 0;
			for (int k = 0; k < N; k++){
            	summa += matrix[i][k];
				summa2 += matrix[j][k];
        	}
			if (summa > summa2){
				for (int h = 0; h < N; h++){
					int n = matrix[i][h];
					matrix[i][h] = matrix[j][h];
					matrix[j][h] = n;
				}
			}
    	}
	}

	cout << "Матрица отсортирована \n";
}

//2 пункт
int func(int a, int b) {
	return pow(a,b);
}

double func(double a, double b) {
	return a + b;
}

int main()
{
	setlocale(0, "");

	cout << "\n1 пункт\n";
	get_matrix("input.txt");
	show_matrix();
	int minimum = min_matrix();
	int maximum = max_matrix();
	if (is_equal(minimum, maximum) and (is_prime(minimum) or is_prime(maximum))) {
		sort();
	}
	show_matrix();
	write_matrix("output.txt");


	cout << "\n2 пункт\n";
	cout << "\nfunc(2, 3) = " << func(2, 3);
	cout << "\nfunc(77, 0) = " << func(77,0);
	cout << "\nfunc(-5.56, 9.45) = " << func(-5.56, 9.45);
	cout << "\nfunc(34.68, 23.67) = " << func(-5.56, 9.45);
}