#include <iostream>
#include <cmath>
#include "inc/matrix.cpp"

using namespace std;


int main() 
{
    Matrix<int> A(3, 3);
    Matrix<int> B(3, 3);
    Matrix<int> C(2, 3);
    cin >> A;
    cout << "-----------------------" << endl;
    /*
    2 5 7
    6 3 4
    5 -2 -3
    */
    cin >> C;
    /*
    6 2 9
    7 2 6
    */
    cout << "-----------------------" << endl;
    cin >> B;
    /*
    1 6 7
    5 7 3
    6 7 7
    */
    cout << "-----------------------" << endl;
    Matrix L =  ~A;
    cout << L << endl;
    L *= A;
    cout << L << endl;
    cout << "------------------------" << endl;
    Matrix D = A + B;
    cout << D;
    cout << "-----------------------" << endl;
    D = D - B;
    cout << D;
    cout << "-----------------------" << endl;
    D += B;
    cout << D;
    cout << "-----------------------" << endl;
    D *= B;
    cout << D;
    cout << "-----------------------" << endl;
    Matrix E = A * C;
    cout << E;
    cout << "-----------------------" << endl;
    Matrix F = C * B;
    cout << F;
    cout << "-----------------------" << endl;
    int Z = B.det();
    cout << Z << endl;
    cout << "-----------------------" << endl;
    cout << A;
    A.delete_n(3);
    cout << "-----------------------" << endl;
    cout << A;
    
}