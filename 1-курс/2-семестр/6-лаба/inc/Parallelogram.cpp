#include <iostream>
#include <cmath>
#include "Shape.cpp"



using namespace std;


class Parallelogram : public Shape
{
private:
    Point m_A;
    Point m_B;
    Point m_C;
public:
    Parallelogram(){}
    Parallelogram(Point A, Point B, Point C, string color): Shape(color)
    {
        m_A = A;
        m_B = B;
        m_C = C;
    }

    int S() override {
        return abs((m_B.x - m_A.x)*(m_C.y - m_A.y)-(m_C.x - m_A.x)*(m_B.y-m_A.y));
    }
    void in(){
        cout << "точка A: " << endl;
        m_A.in();
        cout << "точка B: " << endl;
        m_B.in();
        cout << "точка C: " << endl;
        m_C.in();
        cout << "Цвет: " << endl;
        cin >> m_color;
    }
    string type()override {return "Параллелограмм";}
    string points()override  {return "A(" + m_A.info() + "), B(" + m_B.info() + "), C(" + m_C.info() + ")";}

};
