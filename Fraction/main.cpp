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
	int gett_denominator()const
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
	Fraction operator+(const Fraction& other)const                      //Перегрузка оператора сложения
	{
		Fraction frac_1;
		if (this->denominator == other.denominator)
		{
			frac_1.intedger = this->intedger + other.intedger;
			frac_1.numerator = this->numerator + other.numerator;
			frac_1.denominator = this->denominator;

		}
		else
		{
			frac_1.intedger = this->intedger + other.intedger;
			frac_1.numerator = this->numerator * other.denominator + other.numerator * this->denominator;
			frac_1.denominator = this->denominator * other.denominator;
		}
		if (frac_1.numerator > frac_1.denominator)                         // Вывод целого числа
		{
			frac_1.intedger += frac_1.numerator / frac_1.denominator;
			frac_1.numerator = frac_1.numerator % frac_1.denominator;
		}
		for (int i = 2; i < frac_1.denominator / 2; i++)                  //  Сокращение дроби
		{
			if (frac_1.numerator % i == 0 && frac_1.denominator % i == 0)
			{
				frac_1.numerator /= i;
				frac_1.denominator /= i;
			}
		}
		if (frac_1.numerator == frac_1.denominator)
		{
			frac_1.intedger += 1;
			frac_1.numerator = 0;
			frac_1.denominator = 0;
		}
		return frac_1;
	}
	Fraction operator/(const Fraction& other)const             //Перегрузка оператора деления
	{
		Fraction frac_1, frac_2;
		frac_1.numerator = this->intedger * this->denominator + this->numerator;
		frac_2.numerator = other.intedger * other.denominator + other.numerator;
		frac_1.denominator = this->denominator;
		frac_2.denominator = other.denominator;
		frac_1.numerator = frac_1.numerator * frac_2.denominator;
		frac_1.denominator = frac_1.denominator * frac_2.numerator;
		if (frac_1.numerator > frac_1.denominator)                         // Вывод целого числа
		{																  
			frac_1.intedger = frac_1.numerator / frac_1.denominator;	 
			frac_1.numerator = frac_1.numerator % frac_1.denominator;	  
		}																  
		for (int i = 2; i < frac_1.denominator / 2; i++)                  //  Сокращение дроби
		{																  
			if (frac_1.numerator % i == 0 && frac_1.denominator % i == 0) 
			{															  
				frac_1.numerator /= i;									  
				frac_1.denominator /= i;								  
			}															  
		}	
		if (frac_1.numerator == frac_1.denominator)
		{
			frac_1.intedger += 1;
			frac_1.numerator = 0;
			frac_1.denominator = 0;
		}
		return frac_1;
	}
	void print()
	{
		if (intedger > 0 && numerator > 0 && denominator > 0)
		{
			cout << intedger << "|" << numerator << "/" << denominator << endl;
		}
		else if (intedger != 0 && numerator == 0 && denominator == 0)
		{
			cout << intedger << endl;
		}
		else
		{
			cout << numerator << "/" << denominator << endl;
		}
	}

};



void main()
{
	setlocale(LC_ALL, "");
	Fraction D(2, 3, 5);
	Fraction A(6, 2, 6);
	Fraction C = D + A / D;
	A.print();
	D.print();
	C.print();
}