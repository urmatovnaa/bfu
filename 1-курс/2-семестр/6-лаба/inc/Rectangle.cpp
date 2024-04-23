#include <iostream>
#include <cmath>
#include "Shape.cpp"


using namespace std;


class Rectangle : public Shape
{
private:
    Point m_A;
    Point m_B;
    Point m_C;
    Point m_D;
public:
    Rectangle() {}
    Rectangle(Point A, Point B, Point C, Point D, string color): Shape(color)
    {
        m_A = A;
        m_B = B;
        m_C = C;
        m_D = D;
    }

    int S()override {
        return abs((m_B.x - m_A.x)*(m_A.y - m_C.y));
    }
    void in(){
        cout << "точка A: " << endl;
        m_A.in();
        cout << "точка B: " << endl;
        m_B.in();
        cout << "точка C: " << endl;
        m_C.in();
        cout << "точка D: " << endl;
        m_D.in();
        cout << "Цвет: " << endl;
        cin >> m_color;
    }
    string type()override {return "Прямоугольник";}
    string points()override {return "A(" +m_A.info() +"), B("+ m_B.info()+"), C("+m_C.info()+"), D("+m_D.info()+")";}

};
