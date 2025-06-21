#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;
using std::cout;
using std::cin;
using std::endl;

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(const Fraction& left, const Fraction& right);



class Fraction
{
	int intedger;
	int numerator;
	int denominator;
public:
	int get_intedger()const
	{
		return intedger;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	//-----------------------------------------------------------------------------------
	void set_intedger(int intedger)
	{
		this->intedger = intedger;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		this->denominator = denominator;
	}
	                   //Конструкторы
	Fraction()
	{
		this->intedger = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
explicit Fraction(int integer)
	{
		this->intedger = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->intedger = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_intedger(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->intedger = other.intedger;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	                          //Функции класса
	Fraction& operator=(const Fraction& other)  //оператор присваивания
	{
		this->intedger = other.intedger;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	Fraction operator++()
	{
		intedger++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;
		intedger++;
		return old;
	}
	
	//                  Type-cast operators
 operator int()const
	{
		return intedger + numerator / denominator;
	}

 operator double()const
{
	return intedger + (double)numerator / denominator;
}
	
	//------------------Методы---------------------
	Fraction& to_improper()
	{
		//Целую часть интегрирует в числитель
		numerator += intedger * denominator;
		intedger = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		intedger += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		std::swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	void print()const
	{
		if (intedger)cout << intedger;
		if (numerator)
		{
			if (intedger)cout << "(";
			cout << numerator << "/" << denominator;
			if (intedger)cout << ")";
		}
		else if (intedger == 0)cout << 0;
		cout << endl;
	}
};


Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper();
}
	Fraction operator/(const Fraction & left, const Fraction & right)
	{
		return left * right.inverted();
	}

	//--------------------Логические операторы----------------------
	bool operator==(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return
			left.get_numerator() * right.get_denominator() ==
			right.get_numerator() * left.get_denominator();
	}
	bool operator!=(const Fraction& left, const Fraction& right)
	{
		return !(left == right);
	}
	bool operator>=(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return
			left.get_numerator() * right.get_denominator() >=
			right.get_numerator() * left.get_denominator();
	}
	bool operator<=(Fraction left, Fraction right)
	{
		left.to_improper();
		right.to_improper();
		return
			left.get_numerator() * right.get_denominator() <=
			right.get_numerator() * left.get_denominator();
	}
	std::ostream& operator<<(std::ostream& os, const Fraction& obj)
	{
		if (obj.get_intedger())os << obj.get_intedger();
		if (obj.get_numerator())
		{
			if (obj.get_intedger())os << "(";
			os << obj.get_numerator() << "/" << obj.get_denominator();
			if (obj.get_intedger())os << ")";
		}
		else if (obj.get_intedger() == 0)os << 0;
		return os;
	}
	std::istream& operator>>(std::istream& cin, Fraction& obj)
	{
		const int SIZE = 32;
		char sz_input[SIZE] = {};
		//cin >> sz_input;
		cin.getline(sz_input, SIZE);
		const char delimiters[] = { '/',' ','(',')','.',',',0 };
		int numbers[3] = {};
		int n = 0;
		for (char* pch = strtok(sz_input, delimiters);
			pch && n < 3;
			pch = strtok(NULL, delimiters))numbers[n++] = atoi(pch);
		//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;
		/*-------------
		Фунция strtpk() разбивает строку на токены.
		Раздельтель (delimiters) - это символы, по которым нужно делить строку
		Ещкены (tokens) - это элементы, которые нужно достать из строки
		*/
		switch (n)
		{
		case 1:obj =  Fraction(numbers[0]); break;
		case 2:obj =  Fraction(numbers[0], numbers[1]); break;
		case 3:obj =  Fraction(numbers[0], numbers[1], numbers[2]); break;
		}

		return cin;
	}

	//#define CONSTRUCTORS_CHECK
	//#define ASSIGNMENT_CHECK
	//#define ARITHMETICAL_OPERATORS
	//#define INCREMENT_DECREMENT
	//#define COMPARISON_OPERATORS
   // #define ISTREAM
   //#define CONVERSIONS_FROM_OTHER_TO_CLASS


	void main()
	{
		setlocale(LC_ALL, "");

#ifdef CONSTRUCTORS_CHECK
		Fraction A;			//Default constructor
		A.print();

		Fraction B = 5;		//Single-argument constructor (Конструктор с одним параметром)
		B.print();

		Fraction C(1, 2);	//Constructor
		C.print();

		Fraction D(2, 3, 4);//Constructor
		D.print();

		Fraction E = D;		//Copy constructor
		E.print();

		Fraction F;
		F = E;				//Copy assignment
		F.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ASSIGNMENT_CHECK
		int a, b, c;

		a = b = c = 0;

		cout << a << "\t" << b << "\t" << c << endl;

		Fraction A, B, C;
		cout << delimiter << endl;
		A = B = C = Fraction(2, 3, 4);
		//Fraction(2, 3, 4); // Явный вызов конструктора, который создает временный безымянный объект.
		//Временные безымянные объекты существуют в пределах одного выражения
		cout << delimiter << endl;
#endif // ASSIGNMENT_CHECK

#ifdef ARITHMETICAL_OPERATORS
		Fraction A(1, 2);
		Fraction B(2, 3, 4);
		Fraction C = A / B;
		A.print();
		B.print();
		C.print();
		cout << delimiter << endl;
		A /= B;
		A.print();
		B.print();
#endif // ARITHMETICAL_OPERATORS

#ifdef INCREMENT_DECREMENT
		Fraction A(1, 2);
		Fraction B = A++;
		A.print();
		B.print();
#endif // INCREMENT_DECREMENT

#ifdef COMPARISON_OPERATORS
		cout << (Fraction(1, 2) != Fraction(5, 11)) << endl;
#endif // COMPARISON_OPERATORS

		//Fraction A(1, 2, 3);
		//Fraction B(2, 3, 4);
		//cout << A / B;

#ifdef ISTREAM
		Fraction A;
		cout << "Введите простую дробь: "; cin >> A;
		cout << A << endl;

#endif // ISTREAM
#ifdef CONVERSIONS_FROM_OTHER_TO_CLASS
		Fraction A = (Fraction)5;   //Implicit conversion from less to more
		cout << A << endl;

		Fraction B;
		B = Fraction(8);
		cout << B << endl;

#endif // CONVERSIONS_FROM_OTHER_TO_CLASS
		/*operator type()
		{
			....;
			....;
			....;
		}*/


		Fraction A(2, 3, 4);
		cout << A << endl;
 
		int a = A;
		cout << a << endl;

		double b = A;
		cout << b << endl;

	}






