#include<iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;


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
		cout << "constructor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		//this - этот обьект
		//other -тот обьект
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor:\t" << this << endl;
	}
	//Point(const Point& other) = delete; //Удаляет Конструктор копирования и таким образом запрещает копирование обьектов
	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment:\t\t" << this << endl;
	}

	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	///                    Operators


	//           Metods:
	void print()const
	{
		cout << "X = " << get_x() << "\tY = " << get_y() << endl;
	}
	double distance(const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	
};
double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	return sqrt(x_distance * x_distance + y_distance * y_distance);
}



//#define STRUCT_POINT
//#define CONSTRUCTORS_CHECK
//#define DISTANCE_CHECK
#define ASSIGNMENT_CHECK


#define delimetr "\n---------------------------------------------\n"
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
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);
	A.print();
	B.print();
	cout << delimetr << endl;
	cout << "Растояние от точки А до точки B :" << A.distance(B) << endl;
	cout << delimetr << endl;
	cout << "Растояние от точки B до точки A :" << B.distance(A) << endl;
	cout << delimetr << endl;
	cout << "Растояние между точками A и B :" << distance(A, B) << endl;
	cout << delimetr << endl;
	cout << "Растояние между точками B и A :" << distance(B, A) << endl;
	cout << delimetr << endl;

#endif // DISTANCE_CHECK
#ifdef CONSTRUCTORS_CHECK

	//A.set_y(3); 
	//A.set_x(2);
	//std::cout << A.get_x() << "\t" << A.get_y() << endl;
	//cout << B.get_x() << "\t" << B.get_y() << endl;
	Point A(24, 34);
	//A.print();
	Point B(45, 65);
	//B.print();
	Point C(7, 8);
	C.print();
	Point D = C;  //CopyConstructor
	D.print();
	Point E;
	E = D;   //CopyAssignment
	E.print();

#endif // CONSTRUCTORS_CHECK
#ifdef ASSIGNMENT_CHECK

	int a, b, c;
	a = b = c = 0;
	cout << a << '\t' << b << '\t' << c << endl;

	//Point(2,3):---Здесь мы явно вызываем конструктор и таким образом создаем времкнный безымянный обьект
	cout << Point(2.3).distance(Point(7, 8)) << endl;
	//Временный безымянные обьекты существуют только в пределах одного выражения, они удаляются из памяти ,после того как выражение выполнилось
	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK

}