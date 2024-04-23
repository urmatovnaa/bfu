#include <iostream>
#include <cmath>

using namespace std;


class D_Complex 
{
private:
    double real, imag;
public:
    // 1. Конструктор по умолчанию
    D_Complex(){
        real = 0;
        imag = 0;
    }
    // 2.Конструктор полного заполнения
    D_Complex(double r, double i) : real(r), imag(i) {}

    // 2. Конструктор копирования
    D_Complex(const D_Complex& other) : real(other.real), imag(other.imag) {}

    // 3. Оператор присваивания копированием
    D_Complex& operator=(const D_Complex& other) 
    {
        real = other.real;
        imag = other.imag;
        return *this;
    }

    // 4. Деструктор
    ~D_Complex() 
    {
        cout << "Class deleted"  << endl;
    }

    // 5. Операторы += и +
    D_Complex& operator+=(const D_Complex& other) 
    {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    D_Complex operator+(const D_Complex& other) 
    {
        D_Complex result(*this); 
        result.real += other.real;
        result.imag += other.imag;
        return result; 
    }


    // 6. Операторы *= и *
    D_Complex& operator*=(const D_Complex& other) 
    {
        double n_real = real * other.real - imag * other.imag;
        double n_imag = real * other.imag + imag * other.real;
        real = n_real;
        imag = n_imag;
        return *this;
    }

    D_Complex operator*(const D_Complex& other) 
    {
        return D_Complex(real * other.real - imag * other.imag,
            real * other.imag + imag * other.real);
    }

    // 7. Операторы ++ префиксный и постфиксный (увеличение действительной части числа на 1)
    D_Complex& operator++() 
    {
        ++real;
        return *this;
    }

    D_Complex operator++(int) 
    {
        D_Complex pre = *this;
        ++(*this);
        return pre;
    }

    // 8. Операторы ввода и вывода
    friend ostream& operator<<(ostream& out, const D_Complex& c) 
    {
        out << c.real << " + " << c.imag << "i";
        return out;
    }

    friend istream& operator>> (istream& in, D_Complex& c) 
    {
        in >> c.real >> c.imag;
        return in;
    }
    double absC() {return sqrt(pow(real, 2) + pow(imag, 2));}
    double getReal() {return real;}
    double getImag() {return imag;} 
};



int qC(D_Complex c)
{
    if (c.getReal() > 0 and c.getImag() > 0) {
        return 1;
    }
    else if (c.getReal() == 0 or c.getImag() == 0) {
        if (c.getImag() > 0){return 2;}
        else if (c.getReal() < 0) {return 3;}
        else if (c.getImag() < 0){return 4;}
        return 1;
    }
    else if (c.getReal() < 0 and c.getImag() > 0) {
        return 2;
    }
    else if (c.getReal() < 0 and c.getImag() < 0) {
        return 3;
    }
    else {
        return 4;
    }
}

// Поиск скалярного произведения двух радиус-векторов, соответствующих комплексным числам
double scalarC(D_Complex a, D_Complex b)
{
    return a.getReal() * b.getReal() + a.getImag() * b.getImag();
}

D_Complex MAX_absC(D_Complex a, D_Complex b) 
{
    if (a.absC() > b.absC()) 
    {
        cout << a << endl;
        return a;
    }
    else if (a.absC() < b.absC()) 
    {
        cout << b << endl;
        return b;
    }
    else 
    {
        cout << "Модули равны" << endl;
        return a;
    }
}

int main() 
{
    D_Complex num1;
    D_Complex num2(2, 4);
    D_Complex num3 = num2; 
    D_Complex num4;
    num4 = num3; 

    cout << "Введите число (через пробел): ";
    cin >> num1;

    cout << "копирование: " << num3 << endl;
    cout << "присваивание: " << num4 << endl;

    //Операторы += и +, *= и *
    num1 += num3;
    cout << num1 << endl;
    cout << "num1 + num3: " << num1 + num3 << endl;

    num2 *= num4;
    cout << num2 << endl;
    cout << "n2 * n4: " << num2 * num4 << endl;
    
    //Оператор ++ префиксный и постфиксный 
    D_Complex pre = ++num1; 
    cout << pre << endl;

    cout << "Постфиксный инкремент: " << num2++ << endl;
   
    //Поиск скалярного произведения двух радиус-векторов, соответствующих комплексным числам.
    cout << "Скалярное произведение num1 и num2: " << scalarC(num1,num2) << endl;

    //Поиск максимального по модулю комплексного числа.
    cout << MAX_absC(num1,num2) << endl;

    //Поиск квадранта в котором располагается радиус-вектор.
    cout << qC(num1) << endl;
    cout << qC(num2) << endl;

    return 0;
}