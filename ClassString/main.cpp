#include<Windows.h>
#include<iostream>
using namespace std;
using std::cout;
using std::endl;
using std::cin;

#define delimetr "--------------------------"

class String
{
	int size;
	char* str;
public:
	int get_size()const;
	const char* get_str()const;
	char* get_str();
	// Constructors
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//Operators
	String& operator=(const String& other);
	String& operator=(String&& other);
	//Methods
	const char& operator[](int i)const;
	char& operator[](int i);
	void info()const;

};



int String:: get_size()const
{
	return size;
}
const char* String:: get_str()const
{
	return str;
}
char* String:: get_str()
{
	return str;
}
// Constructors
/*Ключевое слово 'explicit' использовать только в загаловке конструктора*/
String:: String(int size) :size(size), str(new char[this->size] {})
{
	cout << "DefaultConstructor:\t" << this << endl;
}
// :: - Scope operator (Оператор разрешение видимости)
String::String(const char str[]) :String(strlen(str) + 1)
{
	for (int i = 0; str[i]; i++)this->str[i] = str[i];
	cout << "Constructor:\t\t" << this << endl;
}
String::String(const String& other) :String(other.str)
{
	cout << "CopyConstructor:\t" << this << endl;
}

String::String(String&& other) :size(other.size), str(other.str)
{
	other.size = 0;
	other.str = nullptr;
	cout << "MoveConstructor:\t" << this << endl;
}

String::~String()
{
	delete[] str;
	this->str = nullptr;
	this->size = 0;
	cout << "Destructor:\t\t" << this << endl;
}
//Operators
String& String::operator=(const String& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = new char[size] {};
	for (int i = 0; i < size; i++)this->str[i] = other.str[i];
	cout << "CopyAssignment:\t\t" << this << endl;
	return *this;
}

String& String::operator=(String&& other)
{
	if (this == &other)return *this;
	delete[] this->str;
	this->size = other.size;
	this->str = other.str;
	other.size = 0;
	other.str = nullptr;
	cout << "MoveAssignment:\t\t" << this << endl;
	return *this;
}
//Methods
const char& String::operator[](int i)const
{
	return str[i];
}
char& String::operator[](int i)
{
	return str[i];
}
void String::info()const
{
	cout << "Size:\t" << size << endl;
	cout << "Str:\t" << str << endl;
}




String operator+(const String& left, const String& right)
{
	String result  (left.get_size() + right.get_size() - 1);
	for (int i = 0; left.get_str()[i]; i++)
		//result.get_str()[i] = left.get_str()[i];
		result[i] = left[i];
	for (int i = 0; right.get_str()[i]; i++)
		//result.get_str()[left.get_size() - 1 + i] = right.get_str()[i];
	    result[left.get_size() - 1 + i] = right[i];
	cout << "Operator +" << endl;
	return result;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
std::istream& operator>>(std::istream& cin, String& obj)
{
	const int SIZE = 1024; // размер буфера - 1 КБ
	char buffer[SIZE] = {};
	cin >> buffer;
	obj = buffer;
	return cin;
}
std::istream& getline(std::istream& cin, String& obj)
{
	cin.getline(obj.get_str(), obj.get_size());
	return cin;
}

//#define CONSTRUCTOR_CHECK
#define OPERATOR_PLUS
//#define ISTREAM_OPERATOR
//#define CALLING_CONSTRUCTOR

void main()
{
	setlocale(LC_ALL, "");

#ifdef CONSTRUCTOR_CHECK
	String str1(5);// excplisit - constructor нельзя вызвать оператором присвоить, можно вызвать круглых скобок
	str1.info();
	cout << str1 << endl;

	String str2 = "Hello";
	str2 = str2;
	cout << str2 << endl;

	String str3 = str2;  // CopyConstructor
	cout << str3 << endl;

	String str4;
	str4 = str3;
	cout << str4 << endl;
#endif // CONSTRUCTOR_CHECK

#ifdef OPERATOR_PLUS
	String str1 = "Hello";
	String str2 = "World";
	cout << delimetr << endl;
	String str3;
	str3 = str1 + str2;
	cout << delimetr << endl;
	cout << str3 << endl;
	cout << delimetr << endl;
	String str4 = str3;
	cout << str4 << endl;
	cout << delimetr << endl;

#endif // OPERATOR_PLUS

#ifdef ISTREAM_OPERATOR
	String str;
	cout << "Введите строку: ";
	SetConsoleCP(1251);
	//cin >> str;
	//cin.getline(str.get_str(), str.get_size());
	getline(cin, str);
	SetConsoleCP(866);
	cout << str << endl;

#endif // ISTREAM_OPERATOR

#ifdef CALLING_CONSTRUCTOR
	String str1;   //Default constructor
	str1.info();

	String str2(8);  // Single-argument constructor ('int')
	str2.info();

	String str3 = "Hello"; //Singe-argument constructor ('const char')
	str3.info();
	cout << typeid("Hello").name() << endl;

	String str4(); // Default constructor
	/*Не вызывается ни какой конструктор, ни создается ни какой обьект
	Здесь происходит обьявление функции, которая ничего не принимает
	и возвращает обьект типа 'String'
	Пустые круглые скобки не вызывают конструктор*/
	//str4.
	/*Если нужно явно вызвать Default-constructor,это можно сделать {} */
	String str5(8); //Создается строка длиной 8 байт
	String str6{ 8 }; //Создается строка длиной 8 байт,т. е. {} вызывают конструктор.
	String str7{}; //Явный вызов конструктора по умолчанию
	/*{} Следует использовать с осторожностью */

	String str9 = str3; //Коструктор копирования
	str9.info();
#endif // CALLING_CONSTRUCTOR


}