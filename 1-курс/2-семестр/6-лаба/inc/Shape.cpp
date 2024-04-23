#pragma once
#include <iostream>
#include <cmath>

using namespace std;


class Point
{
public:
    short x;
    short y;
    Point(){}
    // 2.Конструктор полного заполнения
    Point(short m_x, short m_y) : x(m_x), y(m_y) {}
    string info(){return to_string(x) + "," + to_string(y);}
    void in(){
        cout << "X: ";
        cin >> x;
        cout << "Y: ";
        cin >> y;
    }
    
};


class Shape 
{
protected:
    string m_color;
public:
    Shape(){}
    Shape(string color) : m_color(color) {}
    virtual int S(){return 0;}
    virtual string points(){return "";}
    virtual string type(){return "";}
    string getcolor(){return m_color;}
};
