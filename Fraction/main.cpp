#include<iostream>

using std::cout;
using std::cin;
using std::endl;

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
	Fraction(int intedger = 0 , int numerator = 0, int denominator = 0)   //Конструктор по умолчанию
	{
			this->intedger = intedger;
			this->numerator = numerator;
			this->denominator = denominator;
	}
	Fraction(const Fraction& other)   //Конструктор копирования
	{
		this->intedger = other.intedger;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	~Fraction(){}             //Диструктор

	                          //Функции класса
	void operator=(const Fraction& other)  //оператор присваивания
	{
		this->intedger = other.intedger;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
	}
	Fraction operator++(int)
	{
		this->intedger++;
		return *this;
	}
	Fraction operator++()
	{
		++this->intedger;
		return *this;
	}
	
	void print()
	{
		if (intedger != 0 && numerator != 0 && denominator > 0)
		{
			cout << intedger << "|" << numerator << "/" << denominator << endl;
		}
		else if (intedger != 0 && numerator == 0 && denominator == 0)
		{
			cout << intedger << endl;
		}
		else if (intedger == 0 && numerator == 0 && denominator == 0)
		{
			cout << '0' << endl;
		}
		else 
		{
			cout << numerator << "/" << denominator << endl;
		}
	}

};
Fraction operator-(const int& left_volue, const Fraction& other);
Fraction operator-(const Fraction& other, const int& right_volue);
Fraction operator-(Fraction& left, Fraction& right);
Fraction operator+(const int& left_volue, const Fraction& other);
Fraction operator+(const Fraction& other, const int& right_volue);
Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator*(const int& left_volue, const Fraction& other);
Fraction operator*(const Fraction& left, const int right_volue);
Fraction operator*(const Fraction& left, Fraction& right);
Fraction operator/(const Fraction& left, const Fraction& right);
Fraction operator/(const int left_volue, Fraction& right);
Fraction operator/(const Fraction& left, const int& right_volue);

void main()
{
	setlocale(LC_ALL, "");
	Fraction A(3, 3, 5);
	Fraction B(7, 3, 7);
	Fraction C = A * B;
	Fraction D = B / 3;
	A.print();
	B.print();
	C.print();
	D.print();
}








Fraction operator-(const int& left_volue,const Fraction& other)//---------------------------------------('2' - A)------------------------------------
{
	Fraction other_1;
	Fraction other_2 = other;
	if (other.get_intedger() < 0)other_2.set_intedger(other_2.get_intedger() * (-1));
	if (left_volue > 0 && other.get_intedger() < 0)
	{
		other_1.set_intedger(left_volue - 1);
		other_1.set_numerator(other_2.get_denominator());
		other_1.set_denominator(other_2.get_denominator());
	}
	else other_1.set_intedger(left_volue);
	other_1.set_intedger(other_1.get_intedger() - other_2.get_intedger());
	other_1.set_numerator(other_1.get_numerator() - other_2.get_numerator());
	other_1.set_denominator(other.get_denominator());
	if (other.get_intedger() < 0)other_1.set_intedger(other_1.get_intedger() * (-1));
	if (other.get_intedger() < 0 && left_volue > 0)
	{
		other_1.set_intedger(other_1.get_intedger() - 1);
		other_1.set_numerator(other_1.get_denominator() - other_1.get_numerator());
	}
	for (int i = 2; i < other_1.get_denominator() / 2; i++)
	{
		if (other_1.get_numerator() % i == 0 && other_1.get_denominator() % i == 0)
		{
			other_1.set_numerator(other_1.get_numerator() / i);
			other_1.set_denominator(other_1.get_denominator() / i);
		}
	}
	if (other_1.get_numerator() == 0)other_1.set_denominator(0);
	if (other_1.get_numerator() < 0)other_1.set_numerator(other_1.get_numerator() * (-1));
	if (other_1.get_numerator() == other_1.get_denominator())
	{
		other_1.set_intedger(other_1.get_intedger() + 1);
		other_1.set_numerator(0);
		other_1.set_denominator(0);
	}
	if (other.get_intedger() < 0)other_1.set_intedger(other_1.get_intedger() * (-1));
	return other_1;
}
Fraction operator-(const Fraction& other, const int& right_volue)//--------------------------------(A - '2')---------------------------------
{
	Fraction other_1 = other;
	other_1.set_intedger(other_1.get_intedger() - right_volue);
	if (other.get_intedger() < 0 && right_volue < 0)
	{
		other_1.set_intedger(other_1.get_intedger() + 1);
		other_1.set_numerator(other_1.get_denominator() - other_1.get_numerator());
	}
	return other_1;
}
Fraction operator-(Fraction& left, Fraction& right)//-----------------------------------------------------(A - B)--------------------------------
{                                                                                                          
	Fraction other = left;
	Fraction other_1 = right;
	other.set_intedger(left.get_intedger() - right.get_intedger());
	if (left.get_intedger() < 0)other.set_numerator(other.get_numerator() * (-1));
	if (right.get_intedger() < 0)other_1.set_numerator(other_1.get_numerator() * (-1));
	other.set_numerator((other.get_numerator() * other_1.get_denominator()) - (other_1.get_numerator() * other.get_denominator()));
	other.set_denominator(left.get_denominator() * right.get_denominator());
	if (other.get_intedger() < 0 && other.get_numerator() > 0)
	{
		other.set_intedger(other.get_intedger() + 1);
		other.set_numerator(other.get_denominator() - other.get_numerator());
	}
	if (other.get_numerator() < 0)other.set_numerator(other.get_numerator() * (-1));
	if (other.get_numerator() > other.get_denominator())
	{
		(other.get_intedger() > 0 ? other.set_intedger(other.get_intedger() + 1) : other.set_intedger(other.get_intedger() - 1));
		other.set_numerator(other.get_denominator() - other.get_numerator());
		if (other.get_numerator() < 0)other.set_numerator(other.get_numerator() * (-1));
	}
	for (int i = 2; i < other.get_denominator() / 2; i++)
	{
		if (other.get_numerator() % i == 0 && other.get_denominator() % i == 0)
		{
			other.set_numerator(other.get_numerator() / i);
			other.set_denominator(other.get_denominator() / i);
		}
	}

	return other;
}
Fraction operator+(const int& left_volue, const Fraction& other)//------------------------------------('2' + A)-----------------------------
{
	Fraction other_1 = other;
	other_1.set_intedger(left_volue + other_1.get_intedger());
	return other_1;
}
Fraction operator+(const Fraction& other, const int& meaning)//------------------------------------(A + '2')----------------------------------
{
	Fraction other_1 = other;
	other_1.set_intedger(other_1.get_intedger() + meaning);
	if (other_1.get_intedger() < 0 && meaning >= 0)
	{
		other_1.set_intedger(other_1.get_intedger() + 1);
		other_1.set_numerator(other_1.get_denominator() - other_1.get_numerator());
	}
	
	return other_1;
}
Fraction operator+(const Fraction& left, const Fraction& right)//----------------------------------(A + B)----------------------------------
{
	Fraction other = left;
	Fraction other_1 = right;
	other_1.set_intedger(other_1.get_intedger() * (-1));
	return other - other_1;
}
Fraction operator*(const int& left_volue, const Fraction& right)//-----------------------------------('2' * A)----------------------------------
{
	Fraction other = right;
	if (other.get_intedger() < 0)other.set_numerator(other.get_numerator() * (-1));
	other.set_numerator((other.get_intedger() * other.get_denominator() + other.get_numerator()) * left_volue);
	if (other.get_numerator() > other.get_denominator() || other.get_numerator() * (-1) > other.get_denominator())
	{
		other.set_intedger(other.get_numerator() / other.get_denominator());
		other.set_numerator(other.get_numerator() % other.get_denominator());
	}
	if (other.get_numerator() < 0)other.set_numerator(other.get_numerator() * (-1));
	if (other.get_numerator() == 0)other.set_denominator(0);
	return other;
}
Fraction operator*(const Fraction& left, const int right_volue)//------------------------------------(A * '2')---------------------------------------
{
	return right_volue * left;
}
Fraction operator*(const Fraction& left, Fraction& right)//--------------------------------------(A * B)----------------------------------------
{
	Fraction other = left;
	Fraction other_1 = right;
	if (left.get_intedger() < 0)other.set_numerator(other.get_numerator() * (-1));
	if (right.get_intedger() < 0)other_1.set_numerator(other_1.get_numerator() * (-1));
	other.set_intedger(0);
	other.set_numerator((left.get_intedger() * other.get_denominator() + other.get_numerator()) * (other_1.get_intedger() * other_1.get_denominator() + other_1.get_numerator()));
	other.set_denominator(other.get_denominator() * other_1.get_denominator());
	if (other.get_numerator() > other.get_denominator() || other.get_numerator() * (-1) > other.get_denominator())
	{
		other.set_intedger(other.get_numerator() / other.get_denominator());
		other.set_numerator(other.get_numerator() % other.get_denominator());
	}
	if (other.get_numerator() < 0)other.set_numerator(other.get_numerator() * (-1));
	if (other.get_numerator() == 0)other.set_denominator(0);
	return other;
}
Fraction operator/(const Fraction& left, const Fraction& right)//--------------------------------(A / B)-----------------------------------
{
	Fraction other_left = left;
	Fraction other_right = right;
	if (other_left.get_intedger() < 0)other_left.set_numerator(other_left.get_numerator() * (-1));
	if (other_right.get_intedger() < 0)other_right.set_numerator(other_right.get_numerator() * (-1));
	if (other_left.get_intedger() != 0)
	{
		other_left.set_numerator(other_left.get_intedger() * other_left.get_denominator() + other_left.get_numerator());
		other_left.set_intedger(0);
	}
	if (other_right.get_intedger() != 0)
	{
		
		other_right.set_denominator(other_right.get_intedger() * other_right.get_denominator() + other_right.get_numerator());
		other_right.set_numerator(right.get_denominator());
		other_right.set_intedger(0);
		if (other_right.get_denominator() < 0)
		{
			other_right.set_denominator(other_right.get_denominator() * (-1));
			other_right.set_numerator(other_right.get_numerator() * (-1));
		}
	}
	else
	{
		other_right.set_numerator(right.get_denominator());
		other_right.set_denominator(right.get_numerator());
	}
	other_left.set_numerator(other_left.get_numerator() * other_right.get_numerator());
	other_left.set_denominator(other_left.get_denominator() * other_right.get_denominator());
	if (other_left.get_numerator() > other_left.get_denominator()|| other_left.get_numerator()*(-1) > other_left.get_denominator())
	{
		other_left.set_intedger(other_left.get_numerator() / other_left.get_denominator());
		other_left.set_numerator(other_left.get_numerator() % other_left.get_denominator());
		if (other_left.get_numerator() < 0)
		{
			other_left.set_numerator(other_left.get_numerator() * (-1));
		}
	}
	for (int i = 2; i < other_left.get_denominator() / 2; i++)
	{
		if (other_left.get_numerator() % i == 0 && other_left.get_denominator() % i == 0)
		{
			other_left.set_numerator(other_left.get_numerator() / i);
			other_left.set_denominator(other_left.get_denominator() / i);
		}
	}
	return other_left;
}
Fraction operator/(const int left_volue, Fraction& right)//--------------------------------------('2' / A)-------------------------------------
{
	Fraction other_left;
	Fraction other_right = right;
	other_left.set_numerator(left_volue);
	other_left.set_denominator(1);
	return other_left / other_right;
}
Fraction operator/(const Fraction& left, const int& right_volue)//-------------------------------(A / '2')------------------------------------
{
	Fraction other_left=left;
	Fraction other_right;
	other_right.set_numerator(right_volue);
	other_right.set_denominator(1);
	return other_left / other_right;
}