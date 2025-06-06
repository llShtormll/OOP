#include<iostream>

using namespace std;
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this-> x = x;
	}
	void set_y(double y)
	{
		this-> y = y;
	}
	//             Constructors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	Point(int x)
	{
		this->x = x;
		this->y = 0;
		cout << "constructor:\t\t" << this << endl;
	}*/
	Point(double x = 0, double y = 0)
	{
		this->x = x;
		this->y = y;
	}
	
	~Point()
	{
		// cout << "Destructor:\t\t" << this << endl;
	}

	//           Metods:
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
	double distance()
	{
		return sqrt(x * x + y * y);
	}
	double distance(Point& A,Point& B)
	{
		Point C(A.x-B.x,A.y-B.y);
		if (C.x < 0)C.x *= (-1);
		if (C.y < 0)C.y *= (-1);
		//C.print();
		return C.distance();
	}
};
//#define STRUCT_POINT
void main()


{
	setlocale(LC_ALL, "");

#ifdef STRUCT_POINT
	int a; //Обьявление переменной 'a' типа 'int'
	Point A; //Обьявление переменной 'A' типа 'Point' 
	//Создание обьекта (экземпляр) 'A' структуры 'Point'
	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;
	Point* pA = &A;
	cout << pA->x << '\t' << pA->y << endl;
#endif // STRUCT_POINT

	//A.set_y(3); 
	//A.set_x(2);
	//std::cout << A.get_x() << "\t" << A.get_y() << endl;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	Point A(24,34);
	//A.print();
	Point B(45,65);
	//B.print();
	Point C;
	double dist = Point(23, 43).distance();
	cout << "Растояние от центра координат к точке : " << dist << endl;
	double dist_2=C.distance(A,B);
	cout <<"Растояние от точки 1 к точке 2 : " << dist_2 << endl;
}