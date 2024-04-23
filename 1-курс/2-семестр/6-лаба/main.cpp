#include <iostream>
#include <cmath>
#include "inc/Parallelogram.cpp"
#include "inc/Rectangle.cpp"
using namespace std;


void ShapeInfo(Shape& shape)
    {
    cout << "Тип: " << shape.type() << endl;
    cout << "Цвет: " << shape.getcolor() << endl;
    cout << "Вершины: " << shape.points() << endl;
    cout << "Площадь: " << shape.S() << endl;
    }


int main() 
{
    Parallelogram par1[2];
    Rectangle rec1[2];

    // A(1,9), B(8,4), C(1,7)
    // A(-1, 4) B(3, 5) C(0, 0)

 
    for (int i = 0; i < 2; i++) {
        cout << "Параллелограмм" << endl;
        par1[i].in();
    }
    
    // A(1, 4) B(5, 4)  C(1, 1) D(5, 1)
    // A(-2, 3) S(2, 3) C(-2, -1) D(2, -1)


    std::cout << "===============" << std::endl;
 
    for (int i = 0; i < 2; i++) {
        cout << "Прямоугольник" << endl;
        rec1[i].in();
    }

    for (int i = 0; i < 2; i++) {
        ShapeInfo(rec1[i]);
        ShapeInfo(par1[i]);
    }    

    return 0;
}