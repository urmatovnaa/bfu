/*Вариант 3.
Квадрат (сторона – целое число < 500)
Конструктор копирования.
Конструктор полного заполнения.
Геттер стороны.
Найти диагональ квадрата.
Геттер всей информации (сторона, диагональ)*/

#include <iostream>
#include <math.h>
#include <fstream>



// 
class Square {
private:
	// Поля
	int c_side;    
public:
	
    Square() {c_side = 1;}
	// Конструктор
	Square(int side)
	{
		setS(side);
	}
    //Конструктор копирования
    Square(const Square &other){ c_side = other.c_side;}

	~Square()
	{
		std::cout << "Class deleted" << std::endl;
    }

	// Сеттеры
	void setS(int side)
	{
		if (side < 0 or side > 500)
		{
			std::cout << "Сторона должна быть меньше 500" << std::endl;
            exit(-1);
		}
		c_side = side;
	}

	// Геттеры
	int getS() { return c_side; }

    std::string getInfo() 
    { 
        return "Сторона " + std::to_string(c_side) + " Диагональ " + std::to_string(Diagonal());
    }

    // Метод
	float Diagonal()
	{
		return  sqrt(2) * c_side;
	}
};



int main()
{


	Square sq(4);
    Square sq2(sq);
	std::cout << sq.getS() << std::endl;
    std::cout << sq.getInfo() << std::endl;
    std::cout << sq2.getInfo() << std::endl;
    sq2.setS(5);
    std::cout << sq.getInfo() << std::endl;
    std::cout << sq2.getInfo() << std::endl;
    sq.setS(577);

	return 0;
}