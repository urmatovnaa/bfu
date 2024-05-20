#include <iostream>
#include <fstream>


template<typename M>
class Matrix {
	int m_n;
    int m_m;
	M** m_mat;

public:
    // Default constructor
    Matrix() : m_n(0), m_m(0), m_mat(nullptr) {}

	Matrix(int n, int m) : m_n(n), m_m(m) {
        if (n > 0 && n < 4 && m > 0 && m < 4){
		    m_mat = new M*[n];
		    for (int i = 0; i < m_n; i++){
			    m_mat[i] = new M[m];
            }
        }
        else {
            std::cout << "Ошибка размеров матрицы" << std::endl;
        }
	}

	// Конструктор копирования
	Matrix(const Matrix& other) : m_n(other.m_n), m_m(other.m_m) {
        m_mat = new M*[m_n];
        for (int i = 0; i < m_n; i++) {
            m_mat[i] = new M[m_m];
            for (int j = 0; j < m_m; j++) {
                m_mat[i][j] = other.m_mat[i][j];
            }
        }
    }

	// Оператор присваивания копирования
	Matrix& operator=(const Matrix& other)
	{
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete[] m_mat;

		m_n = other.m_n;
		m_m = other.m_m;

		m_mat = new M* [m_n];
		for (int i = 0; i < m_n; i++){
			m_mat[i] = new M[m_m];
			for (int j = 0; j < m_m; j++){
				m_mat[i][j] = other.m_mat[i][j];
            }
        }

		return *this;
	}
    // Деструктор
	~Matrix()
	{
		for (int i = 0; i < m_n; i++)
			delete[] m_mat[i];
		delete[] m_mat;
	}
    // Оператор вывода
    friend std::ostream& operator<<(std::ostream& os, const Matrix& matrix) {
        for (int i = 0; i < matrix.m_n; i++) {
            for (int j = 0; j < matrix.m_m; j++) {
                os << matrix.m_mat[i][j] << " ";
            }
            os << std::endl;
        }
        return os;
    }

    // Оператор ввода
    friend std::istream& operator>>(std::istream& is, Matrix& matrix) {
        for (int i = 0; i < matrix.m_n; ++i) {
            for (int j = 0; j < matrix.m_m; ++j) {
                is >> matrix.m_mat[i][j];
            }
        }
        return is;
    }
    // Оператор +
    Matrix operator+(const Matrix& other) {
        if (m_n != other.m_n || m_m != other.m_m) {
            std::cout << "Матрицы должны быть одинаковы" << std::endl;
        }
        Matrix result(m_n, m_m);
        for (int i = 0; i < m_n; i++) {
            for (int j = 0; j < m_m; j++) {
                result.m_mat[i][j] = m_mat[i][j] + other.m_mat[i][j];
            }
        }
        return result;
    }
    // Оператор -
    Matrix operator-(const Matrix& other) {
        if (m_n != other.m_n || m_m != other.m_m) {
            throw std::invalid_argument("Матрицы должны быть одинаковы");
        }
        Matrix result(m_n, m_m);
        for (int i = 0; i < m_n; i++) {
            for (int j = 0; j < m_m; j++) {
                result.m_mat[i][j] = m_mat[i][j] - other.m_mat[i][j];
            }
        }
        return result;
    }
    // Оператор * матриц
    Matrix operator*(const Matrix& other) {
        if (m_m != other.m_n) {
            std::cout << "кол. стобцов должно быть равно кол.строк" << std::endl;
            Matrix result(1, 1);
            result.m_mat[0][0] = 9999;
            return result;
        }
        Matrix result(m_n, other.m_m);
        for (int i = 0; i < m_n; ++i) {
            for (int j = 0; j < other.m_m; ++j) {
                result.m_mat[i][j] = 0;
                for (int k = 0; k < m_m; ++k) {
                    result.m_mat[i][j] += m_mat[i][k] * other.m_mat[k][j];
                }
            }
        }
        return result;
    }
    // Оператор * на число
    Matrix operator*(const M& number) {
        Matrix result(m_n, m_m);
        for (int i = 0; i < m_n; ++i) {
            for (int j = 0; j < m_m; ++j) {
                result.m_mat[i][j] = m_mat[i][j] * number;
            }
        }
        return result;
    }
    // Оператор *= на число
    Matrix operator*=(const M& number) {
        for (int i = 0; i < m_n; ++i) {
            for (int j = 0; j < m_m; ++j) {
                m_mat[i][j] *= number;
            }
        }
        return *this;
    }
    // Оператор *= на матрицу
    Matrix& operator*=(const Matrix& other) {
        *this = (*this * other);
        return *this;
    }
    // Оператор +=
    Matrix operator+=(const Matrix& other) {
        *this = (*this + other);
        return *this;
    }
    // Оператор -=
    Matrix operator-=(const Matrix& other) {
        *this = (*this - other);
        return *this;
    }
    // определитель
    M det(){
        if (m_n != m_m){
            std::cout << "кол столбцов должно быть равно кол.строк" << std::endl;
            return 9999;
        }
        size_t n = 0;
        if (m_n == 1){return m_mat[0][0];}
        if (m_m == 3){
            n += m_mat[0][0] * m_mat[1][1] * m_mat[2][2];
            n += m_mat[2][0] * m_mat[0][1] * m_mat[1][2];
            n += m_mat[1][0] * m_mat[0][2] * m_mat[2][1];
            n -= m_mat[0][2] * m_mat[1][1] * m_mat[2][0];
            n -= m_mat[0][0] * m_mat[2][1] * m_mat[1][2];
            n -= m_mat[1][0] * m_mat[0][1] * m_mat[2][2];
        }
        else if (m_n == 2){
            n = m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0];
        }
        return n;
    }
    // удалить строку
    void delete_n(int p){
        if (m_n >= p and p > 0){
            for (int i = 0; i < m_n; i++) {
                for (int j = 0; j < m_m; j++) {
                    if (i > p)
                        m_mat[i - 1][j] = m_mat[i][j];
                }
                if (i == m_n - 1){
                    m_n = m_n -1;
                    delete[] m_mat[i];
                }
            }
        }
        else {
            std::cout << "Выберите другую строку" << std::endl;
        }
    }

    // кастомный оператор
    Matrix operator~() {
        M determinant = det();
        if (m_n != m_m) {
            throw std::invalid_argument("Матрица должна быть квадратной для вычисления обратной матрицы");
        }
        if (determinant == 0){
            throw std::runtime_error("Обратная матрица не существует, так как определитель равен 0");
        }
        if (m_n == 2) {
            Matrix result(2, 2);
            result.m_mat[0][0] = m_mat[1][1] / determinant;
            result.m_mat[0][1] = -m_mat[0][1] / determinant;
            result.m_mat[1][0] = -m_mat[1][0] / determinant;
            result.m_mat[1][1] = m_mat[0][0] / determinant;
            return result;
        }
        else if (m_n == 3) {
            Matrix result(3, 3);
            result.m_mat[0][0] = (m_mat[1][1] * m_mat[2][2] - m_mat[1][2] * m_mat[2][1]) / determinant;
            result.m_mat[0][1] = -(m_mat[0][1] * m_mat[2][2] - m_mat[0][2] * m_mat[2][1]) / determinant;
            result.m_mat[0][2] = (m_mat[0][1] * m_mat[1][2] - m_mat[0][2] * m_mat[1][1]) / determinant;
            result.m_mat[1][0] = -(m_mat[1][0] * m_mat[2][2] - m_mat[1][2] * m_mat[2][0]) / determinant;
            result.m_mat[1][1] = (m_mat[0][0] * m_mat[2][2] - m_mat[0][2] * m_mat[2][0]) / determinant;
            result.m_mat[1][2] = -(m_mat[0][0] * m_mat[1][2] - m_mat[0][2] * m_mat[1][0]) / determinant;
            result.m_mat[2][0] = (m_mat[1][0] * m_mat[2][1] - m_mat[1][1] * m_mat[2][0]) / determinant;
            result.m_mat[2][1] = -(m_mat[0][0] * m_mat[2][1] - m_mat[0][1] * m_mat[2][0]) / determinant;
            result.m_mat[2][2] = (m_mat[0][0] * m_mat[1][1] - m_mat[0][1] * m_mat[1][0]) / determinant;
            return result;
        }
        return *this * (1 / determinant);
    }

};