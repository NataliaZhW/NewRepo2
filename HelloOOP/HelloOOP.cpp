// HelloOOP.cpp 

#include <iostream>
using namespace std;

class Point
{
    double x;
    double y;
public:
    double getX() const { return x; }
    void setX(double x) { this->x = x; }
    double getY() const { return y; }
    void setY(double y) { this->y = y; }
    double distanse_metod(double x, double y)
    {
        return sqrt(pow(x - this->x, 2) + pow(y - this->y, 2));
    }
};

double distanse_foo(Point First, Point Second)
{
    return sqrt(pow(First.getX() - Second.getX(), 2) + pow(First.getY() - Second.getY(), 2));
}
 //#define STRUCT_POINT

void main()
{
    setlocale(LC_ALL, "");
//#ifdef STRUCT_POINT
    double x;
    double y;
    cout << "Введите x: ";
    cin >> x;
    cout << "Введите y: ";
    cin >> y;
    cout << endl;

    Point A;
    A.setX(2);
    A.setY(3);
    Point B;
    B.setX(3);
    B.setY(3);
    cout << "Расстояние от координат (" << x << ";" << y << ") до точки A: " << A.distanse_metod(x, y)<<"\n";
    cout << "Расстояние между точками А и В: " << distanse_foo(A, B)<< "\n";

    cout << sizeof(A) << "\n";
    cout << sizeof(Point) << "\n";

    
    cout << A.getX() << "\t" << A.getY() << "\n";

    //Point* pA = &A; // Pointer to 'A'
    //cout << pA->x << "\t" << pA->y << "\n";

    cout << "Hello OOP!\n";
//#endif
}