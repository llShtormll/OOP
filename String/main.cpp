#include<iostream>

using namespace std;

class String
{
	int size;       //Pазмер строки в байтах
	char* str;      //Указатель на строку в динамик памяти
public:
	int get_size()const
	{
		return size;
	}
	const char* det_str()const
	{
		return str;
	}
	//---------------Constructors---------------
	explicit String(int size = 80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout << "DefaultConstructor:\t"<< this << endl;
	}
	String(const char str[])
	{
		while(str [size++]);
		this->str = new char[size] {};
		for (int i = 0; str[i]; i++)this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		//конструктор копирования должен выполнить (побитовое копирование)DeepCopy
		//т.е. выделять динамическую память под объект и побитово
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] str;
		this->str = nullptr;
		this->size = 0;
		cout << "Distructor:\t\t" << this << endl;
	}

	//------------------Operators-----------------
	String& operator=(const String& other)
	{
		if (this == &other)return *this;
		delete[] this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}

	void info()const
	{
		cout << "Size:\t" << size << endl;
		cout << "Str:\t" << endl;
	}
};
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.det_str();
}



void main()
{
	setlocale(LC_ALL, "");
	String str1(5); 
	str1.info();// explicit конструктор нельзя вызвать оператором '='
	cout << str1 << endl;

	String str2 = "Hello";
	cout << str2 << endl;
	str2 = str2;
	String str3 = str2; //CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;
}